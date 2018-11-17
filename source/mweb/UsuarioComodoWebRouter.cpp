#include "headers/mweb/WebRouter.h"
#include "headers/controls/UsuarioComodoControl.h"

void WebRouter::registerUsuarioComodoCreate()
{
	CROW_ROUTE(app, "/usuarioComodo/put")
	.methods("PUT"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		Document document;
		document.Parse(req.body.c_str());
		
		if(document.HasMember("idUsuario") && document.HasMember("idComodo"))
		{
			response_ = UsuarioComodoControl::GetControl()->create(document["idUsuario"].GetInt(), document["idComodo"].GetInt());	
		}
		else
		{
			response_ = crow::response(500);
		}
				
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::registerUsuarioComodoDelete()
{
	CROW_ROUTE(app, "/usuarioComodo/delete")
	.methods("DELETE"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		Document document;
		document.Parse(req.body.c_str());
		
		if(document.HasMember("idUsuario") && document.HasMember("idComodo"))
		{
			response_ = UsuarioComodoControl::GetControl()->del(document["idUsuario"].GetInt(), document["idComodo"].GetInt());
		}
		else
		{
			response_ = crow::response(500);
		}
		
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}