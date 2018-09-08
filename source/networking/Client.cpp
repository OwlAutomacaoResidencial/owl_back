#include "../../headers/networking/Client.h"
#include "../../headers/networking/ServerPackets.h"
#include "../../headers/networking/ClientPackets.h"
#include "../../headers/networking/ClientManager.h"
#include "../../headers/logging/Logger.h"
#include "../../headers/networking/Packet.h"


CSClient::CSClient(tcp::socket socket)
	//: socket_(std::move(socket))
    : socket_(std::move(socket)),
	ping_thread(&CSClient::StartPingControl, this),
	input_deadline_(socket_.get_io_service())
{
	cinfo = new CSClientConnectionInfo();
	cinfo->client_id = -1;
	cinfo->timestamp = -1;

	isActive = true;
}

uint16_t CSClient::GetClientId()
{
	return cinfo->client_id;
}

void CSClient::Start()
{
	CSClient::ping_thread.detach();

	CSClient::StartRead();
}

void CSClient::StartRead()
{
	auto self(shared_from_this());

	boost::asio::async_read(socket_,
	boost::asio::buffer(recv_buffer),
	boost::asio::transfer_at_least(0x0001),
	[this, self](boost::system::error_code const& ec, std::size_t recv_size)
	{
		 if ((boost::asio::error::eof == ec) ||
			(boost::asio::error::connection_reset == ec))
		{
			//std::cout << "Error reading data; Code: " << ec << std::endl;
			CSClient::CloseClient();
		}
		else
		{
			CSClient::HandlePacket(std::move(recv_buffer));
			CSClient::StartRead();
		}
	});
}

void CSClient::SendWelcome()
{
	auto self(shared_from_this());

	Packet* welcome_packet = ServerPackets::Welcome(new Packet(cinfo));

    boost::asio::async_write(socket_,
	boost::asio::buffer(welcome_packet->data(),
	welcome_packet->length()),
    [this, self](boost::system::error_code ec, std::size_t transmited)
	{
		if (!ec)
		{
			CLogger::GetLogger()->Log("Sending Welcome Back Packet with %d bytes", transmited);
		}
		else
		{
			CSClient::CloseClient();
		}
	});
}

void CSClient::SendPing()
{
	//if(!isActive)
		//return;

	//CLogger::GetLogger()->Log("Sending Ping Packet");

	auto self(shared_from_this());

	Packet* welcome_packet = ServerPackets::Ping(new Packet(cinfo));

    boost::asio::async_write(socket_,
	boost::asio::buffer(welcome_packet->data(),
	welcome_packet->length()),
    [this, self](boost::system::error_code ec, std::size_t transmited)
	{
		if (!ec)
		{
			//CLogger::GetLogger()->Log("Ping Packet sent with %d bytes", transmited);
		}
		else
		{
			//CSClient::CloseClient();
		}
	});
}

void CSClient::SendSimpleAction(uint8_t value)
{
	auto self(shared_from_this());

	Packet* simple_action_packet = ServerPackets::SimpleAction(new Packet(cinfo), value);

    boost::asio::async_write(socket_,
	boost::asio::buffer(simple_action_packet->data(),
	simple_action_packet->length()),
    [this, self](boost::system::error_code ec, std::size_t transmited)
	{
		if (!ec)
		{
			CLogger::GetLogger()->Log("Sending Simple Action Packet with %d bytes", transmited);
		}
		else
		{
			CSClient::CloseClient();
		}
	});
}

void CSClient::SendSwitchLight(uint8_t index)
{
	auto self(shared_from_this());

	Packet* light_switch_packet = ServerPackets::LightSwitch(new Packet(cinfo), index);

    boost::asio::async_write(socket_,
	boost::asio::buffer(light_switch_packet->data(),
	light_switch_packet->length()),
    [this, self](boost::system::error_code ec, std::size_t transmited)
	{
		if (!ec)
		{
			CLogger::GetLogger()->Log("Sending Light Switch Packet with %d bytes", transmited);
		}
		else
		{
			CSClient::CloseClient();
		}
	});
}

void CSClient::SendDefaultPacket(Packet* packet)
{
	auto self(shared_from_this());

    boost::asio::async_write(socket_,
	boost::asio::buffer(packet->data(),
	packet->length()),
    [this, self](boost::system::error_code ec, std::size_t transmited)
	{
		if (!ec)
		{
			CLogger::GetLogger()->Log("Sending Packet with %d bytes", transmited);
		}
		else
		{
			CSClient::CloseClient();
		}
	});
}

void CSClient::HandlePacket(std::array<char, 1024> packet)
{
	switch((uint8_t) packet[0x0004])
	{
		case WELCOME_PACKET:
		{
			uint8_t client_id_1 = ((uint8_t) packet[0x0000]);
			uint8_t client_id_2 = ((uint8_t) packet[0x0001]);

			cinfo->client_id = ((uint16_t) client_id_1 << 8) | client_id_2;

			uint8_t moduletype = (uint8_t) packet[0x0002];

			//CLogger::GetLogger()->Log("Welcome Packet received from client %d", cinfo->client_id);
			CLogger::GetLogger()->Log("	-> Client [%d] registered successfully as %d module!", cinfo->client_id, moduletype);
			CSClient::SendWelcome();

			if(moduletype == DHT_MODULE)
				background_thread = new boost::thread(boost::bind(&CSClient::temp_humidity_thread, shared_from_this()));
			else if(moduletype == USOLO_MODULE)
				background_thread = new boost::thread(boost::bind(&CSClient::usolo_thread, shared_from_this()));
			else if(moduletype == LDR_MODULE)
				background_thread = new boost::thread(boost::bind(&CSClient::ldr_thread, shared_from_this()));
			else if(moduletype == MQ2_MODULE)
				background_thread = new boost::thread(boost::bind(&CSClient::mq2_thread, shared_from_this()));
			else if(moduletype == MQ6_MODULE)
				background_thread = new boost::thread(boost::bind(&CSClient::mq6_thread, shared_from_this()));
		}
		break;
		case PING_PACKET:
		{
			//CLogger::GetLogger()->Log("Received Pong Packet - Increasing deadline expire time");
			input_deadline_.expires_from_now(boost::posix_time::seconds(7));

			if(!deadline_active)
			{
				//CLogger::GetLogger()->Log("deadline activated");
				input_deadline_.async_wait(
					boost::bind(&CSClient::check_deadline,
					shared_from_this(), &input_deadline_));

				deadline_active = true;
			}
		}
		break;
		case TEMP_HUMIDITY_PACKET:
		{
			uint8_t temp_data = packet[0x0005];
			uint8_t humidity_data = packet[0x0006];

			CLogger::GetLogger()->Log("Temperature Packet received from client %d , %d", cinfo->client_id, temp_data, humidity_data);

			DATA_SHEET::GetDataSheet()->temp = temp_data;
			DATA_SHEET::GetDataSheet()->humidity = humidity_data;
		}
		break;
		case LDR_PACKET:
		{
			uint8_t data = packet[0x0005];

			CLogger::GetLogger()->Log("LDR Packet received from client %d width data %d", cinfo->client_id, data);

			DATA_SHEET::GetDataSheet()->luminosity = data;
		}
		break;
		case MQ2_PACKET:
		{
			uint8_t data = packet[0x0005];

			CLogger::GetLogger()->Log("MQ2 Packet received from client %d width data %d", cinfo->client_id, data);

			DATA_SHEET::GetDataSheet()->mq2_presence = (data == (uint8_t) 0x0001);
		}
		break;
		case MQ6_PACKET:
		{
			uint8_t data = packet[0x0005];

			CLogger::GetLogger()->Log("MQ6 Packet received from client %d width data %d", cinfo->client_id, data);

			DATA_SHEET::GetDataSheet()->mq6_presence = (data == (uint8_t) 0x0001);
		}
		break;
		case USOLO_PACKET:
		{
			uint8_t data = packet[0x0005];

			CLogger::GetLogger()->Log("USolo Packet received from client %d width data %d", cinfo->client_id, data);

			DATA_SHEET::GetDataSheet()->usolo = data;
		}
		break;
		default:
			CLogger::GetLogger()->Log("Invalid Packet received from client %d. Packet OPCode %d", cinfo->client_id, (int) packet[0x0004]);
			break;
	}
}

void CSClient::StartPingControl()
{
	//CLogger::GetLogger()->Log("Starting Ping Control");
	sleep(2);
	while(isActive)
	{
		sleep(2);
		SendPing();
	}
}

void CSClient::CloseClient()
{
	isActive = false;
	deadline_active = false;

	input_deadline_.cancel();

	if(background_thread != NULL)
		background_thread->interrupt();

	CLogger::GetLogger()->Log("	Closing Client [%d] ", cinfo->client_id);
	ClientManager::GetManager()->UnregisterClient(shared_from_this());
}

bool CSClient::disconnected() const
{
	return !socket_.is_open();
}

void CSClient::check_deadline(boost::asio::deadline_timer* deadline)
{
	if (CSClient::disconnected())
		return;

	//CLogger::GetLogger()->Log("Checking Deadline");

	if (deadline->expires_at() <= boost::asio::deadline_timer::traits_type::now())
	{
		//CLogger::GetLogger()->Log("Deadline has been expired!");
		CSClient::CloseClient();
	}
	else
	{
		deadline->async_wait(
		boost::bind(&CSClient::check_deadline,
		shared_from_this(), deadline));
	}
}

void CSClient::usolo_thread()
{
	sleep(2);
	while(isActive)
	{
		CSClient::SendDefaultPacket(ServerPackets::USoloRequest(new Packet(cinfo)));
		sleep(10);
	}
}

void CSClient::temp_humidity_thread()
{
	sleep(2);
	while(isActive)
	{
		CSClient::SendDefaultPacket(ServerPackets::TempHumidityRequest(new Packet(cinfo)));
		sleep(10);
	}
}

void CSClient::ldr_thread()
{
	sleep(2);
	while(isActive)
	{
		CSClient::SendDefaultPacket(ServerPackets::LdrRequest(new Packet(cinfo)));
		sleep(4);
	}
}

void CSClient::mq2_thread()
{
	sleep(2);
	while(isActive)
	{
		CSClient::SendDefaultPacket(ServerPackets::MQ2Request(new Packet(cinfo)));
		sleep(1);
	}
}

void CSClient::mq6_thread()
{
	sleep(2);
	while(isActive)
	{
		CSClient::SendDefaultPacket(ServerPackets::MQ6Request(new Packet(cinfo)));
		sleep(1);
	}
}
