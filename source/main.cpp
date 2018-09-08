#include "../headers/networking/Server.h"
#include "../headers/mweb/WebRouter.h"
#include "../headers/database/mysql_manager.h"


/*#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"*/

#include <boost/thread.hpp>
#include <thread>
#include <string.h>

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

//namespace json = rapidjson;

/*void start_web()
{
	crow::logger::setLogLevel(crow::LogLevel::CRITICAL);
	crow::SimpleApp app;
	
	CROW_ROUTE(app, "/")
    ([](const crow::request&, crow::response& response_) {
			sql::Connection *con = MySQLConnector::getManager()->getConnection();
			sql::Statement *stmt;
			sql::ResultSet *res;
	  
			json::StringBuffer buffer;
			json::Writer<json::StringBuffer> writer(buffer);
			
			con->setSchema("homeon");

			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * FROM SENSOR"); // replace with your statement
			
			writer.StartArray();
			while (res->next()) 
			{
				writer.StartObject();
				writer.Key("nome");
				writer.String(res->getString("nome").c_str());
				writer.EndObject();
			}
			writer.EndArray();
			
			delete res;
			delete stmt;
			delete con;
			
			response_.set_header("Content-Type", "application/json");
			response_.set_header("Server", "HomeOn/0.1 (Crow)");
			response_.write(buffer.GetString());
			response_.end();
    });
	
	app.port(18080).multithreaded().run();
}*/

/*void testDatabase()
{
	try 
	{


	} 
	catch (sql::SQLException &e) 
	{
	  cout << "# ERR: SQLException in " << __FILE__;
	  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  cout << "# ERR: " << e.what();
	  cout << " (MySQL error code: " << e.getErrorCode();
	  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}*/

int main()
{
	bool running = true;

	CLogger::GetLogger()->Log("HomeOn.Central Bootstrap is initializing");

	boost::asio::io_service srv;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), (unsigned int) CORESERVER_TCP_PORT);

	CoreSERVER* core = new CoreSERVER(srv, endpoint);
	core->Start();
	
	boost::thread thread(boost::bind(&boost::asio::io_service::run, &srv));
	thread.detach();
	
	WebRouter* router = new WebRouter();
	router->Start();
	
	while(running)
	{
		int key_pressed = std::cin.get();
		
		if(key_pressed == 0x000A)
		{
			CLogger::GetLogger()->log_console_enabled = false;
			
			while(true)
			{
				std::cout << "Console logging is disabled;" << std::endl << std::endl;
				std::cout << "Options:" << std::endl;
				std::cout << "	1-Send Simple Action" << std::endl;
				std::cout << "	2-View All clients" << std::endl;
				std::cout << "	9-Close HomeOn Central" << std::endl << std::endl;
				std::cout << "	0-Exit action center" << std::endl;
				std::cout << "Enter action: ";
				
				std::string s;
				std::getline(std::cin, s);
				
				int option = atoi(s.c_str());
				
				switch(option)
				{
					case 1:
					{
						std::cout << std::endl;
						
						std::cout << "Informe o número do cliente: ";
						
						std::getline(std::cin, s);
						
						uint16_t client_id = static_cast<uint16_t>(std::stoi(s));
						
						std::shared_ptr<CSClient> client = ClientManager::GetManager()->GetClient(client_id);
						
						if(client == NULL)
							std::cout << "Invalid client!" << std::endl;
						else
						{
							std::cout << "Informe o valor da ação: ";
							
							std::getline(std::cin, s);
							
							int valor = std::stoi(s);
							
							ClientManager::GetManager()->GetClient(client_id)->SendSimpleAction(valor);
							
							std::cout << "Simple action sent!" << std::endl;
						}
					}
					break;
					case 2:
					{
						ClientManager::GetManager()->PrintAllClients();
					}
					break;
					case 3:
					{
						std::cout << std::endl;
						
						std::cout << "Informe o número do cliente: ";
						
						std::getline(std::cin, s);
						
						uint16_t client_id = static_cast<uint16_t>(std::stoi(s));
						
						std::shared_ptr<CSClient> client = ClientManager::GetManager()->GetClient(client_id);
						
						if(client == NULL)
							std::cout << "Invalid client!" << std::endl;
						else
						{
							std::cout << "Informe o valor da ação: ";
							
							std::getline(std::cin, s);
							
							int valor = std::stoi(s);
							
							ClientManager::GetManager()->GetClient(client_id)->SendSwitchLight(valor);
							
							std::cout << "Light Switch Action Sent!" << std::endl;
						}
					}
					break;
					case 9:
						running = false;
						option = 0x00;
					break;
					default:
						break;
				}
				
				if(option == 0x00)
					break;
				
				std::cout << "Want another action? [Y/n] ";
				
				std::getline(std::cin, s);
				
				if(strcmp(s.c_str(), "Y") != 0)
				{
					break;
				}
			}
		}
		
		std::cout << std::endl << std::endl;
		std::cout << "Console Logging is enabled again" << std::endl;
		CLogger::GetLogger()->log_console_enabled = true;
	}
	
	return 0;
}
