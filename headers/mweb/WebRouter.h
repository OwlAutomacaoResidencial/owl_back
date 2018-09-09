#ifndef WEB_ROUTER
#define WEB_ROUTER

#include "crow.h"
#include "headers/logging/Logger.h"
#include "jwt/jwt.hpp"

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

    void before_handle(crow::request& req, crow::response& /*res*/, context& ctx)
    {
        std::string authorization = req.get_header_value("Authorization");
		using namespace jwt::params;

		  auto key = "secret"; //Secret to use for the algorithm
		  //Create JWT object
		  jwt::jwt_object obj{algorithm("HS256"), payload({{"some", "payload"}}), secret(key)};

		  //Get the encoded string/assertion
		  auto enc_str = obj.signature();
		  CLogger::GetLogger()->Log("%s", enc_str);
		if (authorization.compare("zanao@demitido") != 0)
		{
			
		}
    }

    void after_handle(crow::request& /*req*/, crow::response& /*res*/, context& /*ctx*/)
    {
        // no-op
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
	void SignResponse(crow::response* response_);
public:
	WebRouter();
	void Start();
};



#endif