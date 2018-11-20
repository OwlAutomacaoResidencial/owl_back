#ifndef CONTROL_USUARIO_SENSORES
#define CONTROL_USUARIO_SENSORES

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class UsuarioSensorControl
{
public:
	static UsuarioSensorControl* GetControl();
	crow::response ListarComodosAcessiveis(const crow::request* request_, crow::response* response_);
	crow::response create(int idUsuario, int idSensor);
	crow::response del(int idUsuario, int idSensor);
	crow::response listar(int idUsuario);
private:
	static UsuarioSensorControl* m_This;
};

#endif