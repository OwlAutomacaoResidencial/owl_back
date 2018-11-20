#ifndef WEB_ROUTER
#define WEB_ROUTER

#include "crow.h"
#include "crow/common.h"
#include "headers/logging/Logger.h"

#include "rapidjson/document.h"

#include "headers/mweb/MWebSession.h"

#include "stdio.h"

using namespace crow;

#define WEB_ROUTER_PORT 18080

struct OwlMiddleware 
{
    std::string message;

    OwlMiddleware() 
    {
        message = "foo";
    }

    void setMessage(std::string newMsg)
    {
        message = newMsg;
    }

    struct context
    {
    };
 
	void before_handle(crow::request& req, crow::response& res, context& /*ctx*/)
    {
		switch(req.method) {
			case HTTPMethod::Options:
				res = crow::response(202);
				res.add_header("Access-Control-Allow-Origin", "*");
				res.add_header("Access-Control-Allow-Methods", "POST, GET, DELETE, PUT, OPTIONS");
				res.add_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
				res.end();
			break;
			default:
				
			break;
		}
		
    }

    void after_handle(crow::request& /*req*/, crow::response& res, context& /*ctx*/)
    {
		res.set_header("Content-Type", "application/json");
		res.set_header("Server", "HomeOn/0.2 (Crow)");
		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_header("Access-Control-Allow-Methods", "POST, GET, DELETE, PUT, OPTIONS");
		res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    }
};

class WebRouter
{
private:
	crow::App<OwlMiddleware> app;
	void start_app();
	void RegisterLogin();
	void RegisterSensorRoute();
	void RegisterActualHumidity();
	void RegisterActualTemperature();
	void RegisterSensorAction();
	void RegisterLightSwitch();
	void RegisterActualUSolo();
	void RegisterComodosRoute();
	void RegisterUsuariosRoute();
	void RegisterComodosDisponiveisRoute();
	void RegisterSensorPorComodoRoute();
	
	void RegisterRecuperarUsuario();
	void RegisterUsuarioRegister();
	
	void RegisterComodoCreate();
	void RegisterComodoDelete();
	
	void registerUsuarioComodoCreate();
	void registerUsuarioComodoDelete();
	
	void registerUsuarioSensorCreate();
	void registerUsuarioSensorDelete();
	void registerSensoresUsuario();
	
	void registerOcorrencias();
	
	void SignResponse(crow::response* response_);
public:
	WebRouter();
	void Start();
};



#endif