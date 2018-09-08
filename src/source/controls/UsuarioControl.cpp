#include "../../headers/controls/UsuarioControl.h"
#include "../../headers/database/dao/DAOUsuarios.h"

#include "src/headers/json/serializer/UsuarioSerializer.h"

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

void UsuarioControl::Login(const crow::request* req, crow::response* response_)
{
		auto x = crow::json::load(req->body);
		
		if (!x)
		{
			crow::response auth_fail = crow::response(401);
			response_ = &auth_fail;
			return;
		}
			
		std::string login = x["login"].s();
		std::string passwd = x["passwd"].s();
		
		Usuario* usr = DAOUsuario::GetDAO()->Login(login, passwd);
		
		if(usr == NULL)
		{
			crow::response auth_fail = crow::response(401);
			response_ = &auth_fail;
			return;
		}
		
		json::StringBuffer buffer;
		json::Writer<json::StringBuffer> writer(buffer);
		
		UsuarioSerializer::GetSerializer()->serialize(&writer, usr);
		
		response_->write(buffer.GetString());
}