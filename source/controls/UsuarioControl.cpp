#include "../../headers/controls/UsuarioControl.h"
#include "../../headers/database/dao/DAOUsuarios.h"

#include "headers/logging/Logger.h"

#include "headers/json/serializer/UsuarioSerializer.h"

UsuarioControl* UsuarioControl::m_This = NULL;

UsuarioControl* UsuarioControl::GetControl()
{
	if(m_This == NULL)
		m_This = new UsuarioControl();
		
	return m_This;
}

void UsuarioControl::ListarTodos(crow::response* response_)
{
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	UsuarioSerializer::GetSerializer()->serializeUsuarioList(&writer, DAOUsuario::GetDAO()->GetUsuarios());
	response_->write(buffer.GetString());
}

crow::response UsuarioControl::Login(const crow::request* req, crow::response* response_)
{
	auto x = crow::json::load(req->body);
	
	if (!x)
	{
		return crow::response(401);
	}
		
	std::string login = x["login"].s();
	std::string passwd = x["passwd"].s();
	
	Usuario* usr = DAOUsuario::GetDAO()->Login(login, passwd);
	
	if(usr == NULL)
	{
		return crow::response(401);
	}
	
	CLogger::GetLogger()->Log("Login accepted.");
	
	json::StringBuffer buffer;
	json::Writer<json::StringBuffer> writer(buffer);
	
	crow::response user_response = crow::response(200);
	
	UsuarioSerializer::GetSerializer()->serialize(&writer, usr);
	user_response.write(buffer.GetString());
	
	return user_response;
}