#pragma once
#ifndef CORE_SERVER
#define CORE_SERVER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "../logging/Logger.h"
#include "Client.h"
#include "ClientManager.h"
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

#define CORESERVER_TCP_PORT 1500

class CoreSERVER
{
private:
	tcp::acceptor acceptor_;
	tcp::socket socket_;
	void RegisterClient(std::shared_ptr<CSClient> client);
	void Listen();
public:
	CoreSERVER(boost::asio::io_service& io_service, const boost::asio::ip::tcp::endpoint& endpoint);
	void Start();
};

#endif // !CORE_SERVER