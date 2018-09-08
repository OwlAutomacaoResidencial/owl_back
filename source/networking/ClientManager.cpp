#include "../../headers/networking/ClientManager.h"

ClientManager* ClientManager::m_this = NULL;

ClientManager* ClientManager::GetManager()
{
	if(m_this == NULL)
	{
		m_this = new ClientManager();
	}
	return m_this;
}

void ClientManager::RegisterClient(std::shared_ptr<CSClient> client)
{
	m_this->clients.insert(client);
}

void ClientManager::UnregisterClient(std::shared_ptr<CSClient> client)
{
	m_this->clients.erase(client);
}

void ClientManager::PrintAllClients()
{
	std::cout << " - Printing all connected " << m_this->clients.size() << " clients " << std::endl;
	
	for(std::shared_ptr<CSClient> client : m_this->clients)
	{
		std::cout << "	[" << client->GetClientId() << "] " << std::endl;
	}
}

std::shared_ptr<CSClient> ClientManager::GetClient(uint16_t client_id)
{
	for(std::shared_ptr<CSClient> client : m_this->clients)
	{
		if(client->GetClientId() == client_id)
			return client;
	}
	return NULL;
}