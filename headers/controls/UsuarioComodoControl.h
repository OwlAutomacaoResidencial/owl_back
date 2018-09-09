#ifndef CONTROL_USUARIO_COMODOS
#define CONTROL_USUARIO_COMODOS

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class UsuarioComodoControl
{
public:
	static UsuarioComodoControl* GetControl();
	crow::response ListarComodosAcessiveis(const crow::request* request_, crow::response* response_);
private:
	static UsuarioComodoControl* m_This;
};

#endif