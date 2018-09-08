#ifndef CONTROL_SENSORES
#define CONTROL_SENSORES

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class SensorControl
{
public:
	static SensorControl* GetControl();
	void ListarTodos(crow::response* response_);
	void ListarPorCodigoComodo(crow::response* response_, int comodo);
private:
	static SensorControl* m_This;
};

#endif