#ifndef CONTROL_USUARIOS
#define CONTROL_USUARIOS

#include "crow.h"
#include "rapidjson/prettywriter.h"
#include "headers/usuarios/usuario.h"

using namespace rapidjson;

namespace json = rapidjson;

class UsuarioControl
{
public:
	static UsuarioControl* GetControl();
	Usuario* Login(const std::string login, const std::string passwd);
	crow::response Register(const std::string body);
	crow::response recuperarUsuario(int idUsuario);
	void ListarTodos(crow::response* response_);
private:
	static UsuarioControl* m_This;
};

#endif