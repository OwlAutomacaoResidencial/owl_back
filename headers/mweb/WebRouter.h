#ifndef WEB_ROUTER
#define WEB_ROUTER

#include "crow.h"

#define WEB_ROUTER_PORT 18080

class WebRouter
{
private:
	crow::SimpleApp app;
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
	void RegisterSensorPorComodoRoute();
	void SignResponse(crow::response* response_);
public:
	WebRouter();
	void Start();
};



#endif