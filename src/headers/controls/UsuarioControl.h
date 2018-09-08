#ifndef CONTROL_USUARIOS
#define CONTROL_USUARIOS

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class UsuarioControl
{
public:
	static UsuarioControl* GetControl();
	void Login(const crow::request* request_, crow::response* response_);
	void ListarTodos(crow::response* response_);
private:
	static UsuarioControl* m_This;
};

#endif