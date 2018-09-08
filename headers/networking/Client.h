#pragma once
#ifndef CORE_SERVER_CLIENT
#define CORE_SERVER_CLIENT

#include <thread>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/bind.hpp>

#include "../database/datasheet.h"
#include "Packet.h"

using boost::asio::ip::tcp;
using boost::thread;

#define LIGHT_MODULE 		0x0001
#define DHT_MODULE			0x0002
#define BUZZER_MODULE	0x0003
#define LDR_MODULE			0x0004
#define MQ2_MODULE			0x0005
#define MQ6_MODULE			0x0006
#define USOLO_MODULE		0x0007

class CSClient :
	public std::enable_shared_from_this<CSClient>
{
private:
	tcp::socket socket_;
	std::thread ping_thread;
	boost::asio::deadline_timer input_deadline_;
	CSClientConnectionInfo* cinfo;
	std::array<char, 1024> recv_buffer;
	
	boost::thread* background_thread;
	
	bool isActive;
	bool deadline_active = false;
	
	void StartRead();
	bool disconnected() const;
	void check_deadline(boost::asio::deadline_timer* deadline);
	
	void usolo_thread();
	void temp_humidity_thread();
	void ldr_thread();
	void mq2_thread();
	void mq6_thread();
	
	void SendDefaultPacket(Packet* packet);
public:
	CSClient(tcp::socket socket);
	uint16_t GetClientId();
	
	void Start();
	void HandlePacket(std::array<char, 1024> packet);
	void SendWelcome();
	void SendPing();
	void SendSimpleAction(uint8_t value);
	void SendSwitchLight(uint8_t value);
	
	void CloseClient();
	void StartPingControl();
};

#endif // !CSClient