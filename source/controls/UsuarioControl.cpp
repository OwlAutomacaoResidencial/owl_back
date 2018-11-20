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

Usuario* UsuarioControl::Login(const std::string login, const std::string passwd)
{
	Usuario* usr = DAOUsuario::GetDAO()->Login(login, passwd);
	
	if(usr == NULL)
	{
		return NULL;
		//return crow::response(401);
	}
	
	return usr;
}

crow::response UsuarioControl::recuperarUsuario(int idUsuario)
{
	Usuario* usr = DAOUsuario::GetDAO()->recuperarUsuario(idUsuario);
	
	if(usr == NULL)
	{
		return crow::response(200);
	}
	
	json::StringBuffer buffer;
	json::Writer<json::StringBuffer> writer(buffer);
	
	UsuarioSerializer::GetSerializer()->serialize(&writer, usr);
	
	crow::response user_response = crow::response(200);
	user_response.write(buffer.GetString());
	
	return user_response;
}

crow::response UsuarioControl::Register(const std::string body)
{
	Usuario* user = UsuarioSerializer::GetSerializer()->parse(body);
	
	user = DAOUsuario::GetDAO()->Register(user);
	
	json::StringBuffer buffer;
	json::Writer<json::StringBuffer> writer(buffer);
	
	UsuarioSerializer::GetSerializer()->serialize(&writer, user);
	
	crow::response user_response = crow::response(200);
	user_response.write(buffer.GetString());
	
	return user_response;
}