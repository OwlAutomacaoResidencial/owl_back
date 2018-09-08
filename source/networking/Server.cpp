#include "../../headers/networking/Server.h"
#include "../../headers/networking/Client.h"
#include "../../headers/networking/ClientManager.h"

using namespace std;

CoreSERVER::CoreSERVER(boost::asio::io_service& io_service, const tcp::endpoint& endpoint)
    : acceptor_(io_service, endpoint),
      socket_(io_service)
{
	try
	{
		CLogger::GetLogger()->Log("HomeOn.Central CoreServer initializing");
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void CoreSERVER::Start()
{
	CLogger::GetLogger()->Log("HomeOn.Central CoreServer is listening on port %d\n\n", CORESERVER_TCP_PORT);
	
	CoreSERVER::Listen();
}

void CoreSERVER::Listen()
{
	try
	{
		acceptor_.async_accept(socket_, [this](boost::system::error_code ec)
		{
			if (!ec)
			{
				CoreSERVER::RegisterClient(std::make_shared<CSClient>(std::move(socket_))->shared_from_this());	
			}
			else
				std::cerr << "Error on accepting connection. Error Code: " << ec << std::endl;
			
			Listen();
		});
	}
	catch (boost::system::system_error const& e)
	{
		std::cerr << "Warning: could not accept connection : " << e.what() << std::endl;
	}
}

void CoreSERVER::RegisterClient(std::shared_ptr<CSClient> client)
{
	ClientManager::GetManager()->RegisterClient(client);
	client->Start();
}
