#include "headers/mweb/WebRouter.h"

#include "headers/controls/SessionControl.h"
#include "headers/controls/UsuarioControl.h"

void WebRouter::RegisterLogin()
{
	CROW_ROUTE(app, "/login")
	.methods("OPTIONS"_method, "POST"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		response_ = SessionControl::GetControl()->Login(&req, &response_);
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterUsuariosRoute()
{
	CROW_ROUTE(app, "/usuarios")
    ([&](const crow::request&, crow::response& response_) 
	{
		UsuarioControl::GetControl()->ListarTodos(&response_);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterUsuarioRegister()
{
	CROW_ROUTE(app, "/usuario")
	.methods("PUT"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		response_ = UsuarioControl::GetControl()->Register(req.body);
		
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterRecuperarUsuario()
{
	CROW_ROUTE(app, "/recuperarUsuario/<int>")
	.methods("GET"_method)
	([&](const crow::request& req, crow::response& response_, int idUsuario) 
	{
		response_ = UsuarioControl::GetControl()->recuperarUsuario(idUsuario);
		
		CLogger::GetLogger()->Log("Response Code %d", response_.code);
		WebRouter::SignResponse(&response_);
	});
}