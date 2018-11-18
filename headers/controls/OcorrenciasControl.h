#ifndef CONTROL_OCORRENCIAS
#define CONTROL_OCORRENCIAS

#include "crow.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;

namespace json = rapidjson;

class OcorrenciaControl
{
public:
	static OcorrenciaControl* getControl();
	crow::response listarTodos();
private:
	static OcorrenciaControl* m_This;
};

#endif