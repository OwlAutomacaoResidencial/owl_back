#ifndef USUARIOSERIALIZER
#define USUARIOSERIALIZER

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "headers/usuarios/usuario.h"

#include "headers/logging/Logger.h"

#include <vector>

using namespace rapidjson;

namespace json = rapidjson;

class UsuarioSerializer
{
public:
	static UsuarioSerializer* GetSerializer();
	void serialize(json::Writer<json::StringBuffer>* writer, Usuario* usr);
	void serializeUsuarioList(json::Writer<json::StringBuffer>* writer, std::vector<Usuario*> usuarios);
	
	Usuario* parse(std::string json);
private:
	static UsuarioSerializer* m_This;
};

#endif