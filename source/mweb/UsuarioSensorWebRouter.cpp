#include "headers/mweb/WebRouter.h"

#include "headers/controls/UsuarioSensorControl.hpp"

void WebRouter::registerUsuarioSensorCreate()
{
	CROW_ROUTE(app, "/usuarioSensor/put")
	.methods("PUT"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		Document document;
		document.Parse(req.body.c_str());
		
		if(document.HasMember("idUsuario") && document.HasMember("idSensor"))
		{
			response_ = UsuarioSensorControl::GetControl()->create(document["idUsuario"].GetInt(), document["idSensor"].GetInt());	
		}
		else
		{
			response_ = crow::response(500);
		}
				
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::registerUsuarioSensorDelete()
{
	CROW_ROUTE(app, "/usuarioSensor/delete")
	.methods("DELETE"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		Document document;
		document.Parse(req.body.c_str());
		
		if(document.HasMember("idUsuario") && document.HasMember("idSensor"))
		{
			response_ = UsuarioSensorControl::GetControl()->del(document["idUsuario"].GetInt(), document["idSensor"].GetInt());
		}
		else
		{
			response_ = crow::response(500);
		}
		
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::registerSensoresUsuario()
{
	CROW_ROUTE(app, "/usuarioSensor/<int>")
	.methods("GET"_method)
	([&](const crow::request& req, crow::response& response_, int idUsuario) 
	{
		response_ = UsuarioSensorControl::GetControl()->listar(idUsuario);
		
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}