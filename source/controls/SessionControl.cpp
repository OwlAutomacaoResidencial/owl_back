#include "headers/controls/SessionControl.h"
#include "headers/controls/UsuarioControl.h"

#include "headers/json/serializer/MWebSessionSerializer.h"

#include "headers/mweb/JwtValidator.hpp"

#include "headers/logging/Logger.h"

SessionControl* SessionControl::m_This = NULL;

SessionControl* SessionControl::GetControl()
{
	if(m_This == NULL)
		m_This = new SessionControl();
		
	return m_This;
}

crow::response SessionControl::Login(const crow::request* req, crow::response* response_)
{
	auto x = crow::json::load(req->body);
	
	if (!x)
	{
		CLogger::GetLogger()->Log("No body %s", req->body);
		return crow::response(401);
	}
	
	std::string login = x["login"].s();
	std::string passwd = x["passwd"].s();
	
	Usuario* usr = UsuarioControl::GetControl()->Login(login, passwd);
	
	if(usr == NULL) {
		return crow::response(401);
	}
	
	CLogger::GetLogger()->Log("Login accepted.");
	
	MWebSession* session = new MWebSession();
	session->usuario = usr;
	session->token = generateToken(session);
	
	json::StringBuffer buffer;
	json::Writer<json::StringBuffer> writer(buffer);
	
	crow::response user_response = crow::response(200);
	
	MWebSessionSerializer::GetSerializer()->serialize(&writer, session);
	user_response.write(buffer.GetString());
	
	return user_response;
}