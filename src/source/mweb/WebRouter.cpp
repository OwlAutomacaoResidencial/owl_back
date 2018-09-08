#include "src/headers/mweb/WebRouter.h"

#include "src/headers/networking/Server.h"

#include "src/headers/controls/UsuarioControl.h"
#include "src/headers/controls/SensorControl.h"
#include "src/headers/controls/ComodoControl.h"

#include "rapidjson/prettywriter.h"

#include "src/headers/sensores/SensorManager.h"

#include "src/headers/json/serializer/SensorSerializer.h"

#include "src/headers/database/datasheet.h"

#include <thread>

using namespace rapidjson;

WebRouter::WebRouter()
{
	crow::logger::setLogLevel(crow::LogLevel::CRITICAL);
}

void WebRouter::start_app()
{
	RegisterLogin();
	RegisterSensorRoute();
	RegisterActualHumidity();
	RegisterActualTemperature();
	RegisterLightSwitch();
	RegisterActualUSolo();
	RegisterSensorAction();
	RegisterUsuariosRoute();
	RegisterComodosRoute();
	RegisterSensorPorComodoRoute();
	
	app.port(WEB_ROUTER_PORT).multithreaded().run();
}

void WebRouter::Start()
{
	std::thread web_t(&WebRouter::start_app, this);
	web_t.detach();
}

void WebRouter::SignResponse(crow::response* response_)
{
	response_->set_header("Content-Type", "application/json");
	response_->set_header("Server", "HomeOn/0.1 (Crow)");
	response_->end();
}

void WebRouter::RegisterActualTemperature()
{
	CROW_ROUTE(app, "/temperaturaAtual")
    ([&](const crow::request&, crow::response& response_) 
	{
		std::string result = "{\n	\"temperatura\":\"";
		result = result + std::to_string(DATA_SHEET::GetDataSheet()->temp);
		result = result + "\"\n}";
		
		response_.write(result.c_str());
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterActualHumidity()
{
	CROW_ROUTE(app, "/umidadeAtual")
    ([&](const crow::request&, crow::response& response_) 
	{
		std::string result = "{\n	\"umidade\":\"";
		result = result + std::to_string(DATA_SHEET::GetDataSheet()->humidity);
		result = result + "\"\n}";
		
		response_.write(result.c_str());
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterActualUSolo()
{
	CROW_ROUTE(app, "/umidadeSoloAtual")
    ([&](const crow::request&, crow::response& response_) 
	{
		std::string result = "{\n	\"umidadeSolo\":\"";
		result = result + std::to_string(DATA_SHEET::GetDataSheet()->usolo);
		result = result + "\"\n}";
		
		response_.write(result.c_str());
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterSensorAction()
{
	CROW_ROUTE(app, "/acaoSensor")
	.methods("POST"_method)
	([](const crow::request& req)
	{
		auto x = crow::json::load(req.body);
		
		if (!x)
			return crow::response(400);
			
		int codigoSensor = x["codigoSensor"].i();
		int action = x["action"].i();
		
		bool sended = HandleNewAction(codigoSensor, action);

		if(sended)
			return crow::response(200);
		else 
			return crow::response(400);
	});
}

void WebRouter::RegisterLogin()
{
	CROW_ROUTE(app, "/login")
	.methods("POST"_method)
	([&](const crow::request& req, crow::response& response_) 
	{
		UsuarioControl::GetControl()->Login(&req, &response_);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterSensorRoute()
{
	CROW_ROUTE(app, "/sensores")
    ([&](const crow::request&, crow::response& response_) 
	{
		/*json::StringBuffer buffer;
		json::Writer<json::StringBuffer> writer(buffer);
		
		sql::Connection* con = MySQLConnector::getManager()->getConnection();
		sql::ResultSet* sensores = GetAllSensores(con);
		
		serializeList(&writer, sensores);
		
		delete con;
		delete sensores;*/
		
		SensorControl::GetControl()->ListarTodos(&response_);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterComodosRoute()
{
	CROW_ROUTE(app, "/comodos")
    ([&](const crow::request&, crow::response& response_) 
	{
		ComodoControl::GetControl()->ListarTodos(&response_);
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

void WebRouter::RegisterSensorPorComodoRoute()
{
	CROW_ROUTE(app, "/sensor/comodo/<int>")
    ([&](const crow::request&, crow::response& response_, int comodo) 
	{
		SensorControl::GetControl()->ListarPorCodigoComodo(&response_, comodo);
		WebRouter::SignResponse(&response_);
	});
}

void WebRouter::RegisterLightSwitch()
{
	CROW_ROUTE(app, "/lightswitch/<int>/<int>")
    ([&](const crow::request&, crow::response& response_, int sensorid, int index) 
	{
		std::shared_ptr<CSClient> module = ClientManager::GetManager()->GetClient(sensorid);
		
		if(module != NULL)
		{
			module->SendSwitchLight(index);
			response_ = crow::response(200);
		}
		else
			response_ = crow::response(500);

		
		WebRouter::SignResponse(&response_);
	});
}