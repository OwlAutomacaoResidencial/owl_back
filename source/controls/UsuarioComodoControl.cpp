#include "headers/controls/UsuarioComodoControl.h"

#include "headers/database/dao/DAOComodos.h"
#include "headers/database/dao/DAOUsuarios.h"
#include "headers/database/dao/DAOUsuarioComodo.h"

#include "headers/json/serializer/ComodoSerializer.h"

#include "headers/logging/Logger.h"

UsuarioComodoControl* UsuarioComodoControl::m_This = NULL;

UsuarioComodoControl* UsuarioComodoControl::GetControl()
{
	if(m_This == NULL)
		m_This = new UsuarioComodoControl();
		
	return m_This;
}

crow::response UsuarioComodoControl::ListarComodosAcessiveis(const crow::request* request_, crow::response* response_)
{
	auto x = crow::json::load(request_->body);
	
	if (!x)
	{
		return crow::response(500);
	}
	
	std::vector<Comodo*> listaComodos;
	CLogger::GetLogger()->Log("Retrying Comodos");
	
	int idUsuario = x["idUsuario"].i();
	
	std::string user_perfil = DAOUsuario::GetDAO()->GetPerfil(idUsuario);
	
	if (user_perfil.compare("Dono") == 0)
	{
		CLogger::GetLogger()->Log("User DONO! Retrying all");
		listaComodos = DAOComodo::GetDAO()->GetComodos();
	}
	else
	{
		CLogger::GetLogger()->Log("Commom User! Retrying user-defined only");
		listaComodos = DAOComodo::GetDAO()->GetComodosPorUsuario(idUsuario);	
	}
	
	json::StringBuffer buffer;
	json::Writer<json::StringBuffer> writer(buffer);
	
	crow::response user_response = crow::response(200);
	
	ComodoSerializer::GetSerializer()->serializeComodoList(&writer, listaComodos);
	user_response.write(buffer.GetString());
	
	return user_response;
}

crow::response UsuarioComodoControl::create(int idUsuario, int idComodo)
{
	DAOUsuarioComodo::getDAO()->create(idUsuario, idComodo);
	
	return crow::response(200);
}

crow::response UsuarioComodoControl::del(int idUsuario, int idComodo)
{
	DAOUsuarioComodo::getDAO()->del(idUsuario, idComodo);
	
	return crow::response(200);
}