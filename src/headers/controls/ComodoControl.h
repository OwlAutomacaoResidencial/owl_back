#ifndef CONTROL_COMODOS
#define CONTROL_COMODOS

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class ComodoControl
{
public:
	static ComodoControl* GetControl();
	void ListarTodos(crow::response* response_);
private:
	static ComodoControl* m_This;
};

#endif