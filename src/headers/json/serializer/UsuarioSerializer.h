#ifndef USUARIOSERIALIZER
#define USUARIOSERIALIZER

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "src/headers/usuarios/usuario.h"

#include <vector>

namespace json = rapidjson;

class UsuarioSerializer
{
public:
	static UsuarioSerializer* GetSerializer();
	void serialize(json::Writer<json::StringBuffer>* writer, Usuario* usr);
	void serializeUsuarioList(json::Writer<json::StringBuffer>* writer, std::vector<Usuario*> usuarios);
private:
	static UsuarioSerializer* m_This;
};

#endif