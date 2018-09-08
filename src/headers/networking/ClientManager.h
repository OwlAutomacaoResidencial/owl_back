#pragma once
#ifndef CORE_SERVER_CLIENT_MANAGER
#define CORE_SERVER_CLIENT_MANAGER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "../logging/Logger.h"
#include "Client.h"

class ClientManager
{
private:
	std::set<std::shared_ptr<CSClient>> clients;
	
	static ClientManager* m_this;
public:
	static ClientManager* GetManager();
	void RegisterClient(std::shared_ptr<CSClient> client);
	void UnregisterClient(std::shared_ptr<CSClient> client);
	
	void PrintAllClients();
	
	std::shared_ptr<CSClient> GetClient(uint16_t client_id);
};



#endif