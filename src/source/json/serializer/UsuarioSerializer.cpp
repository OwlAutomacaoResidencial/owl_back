#include "src/headers/json/serializer/UsuarioSerializer.h"

UsuarioSerializer* UsuarioSerializer::m_This = NULL;

UsuarioSerializer* UsuarioSerializer::GetSerializer()
{
	if(m_This == NULL)
		m_This = new UsuarioSerializer();
		
	return m_This;
}

void UsuarioSerializer::serialize(json::Writer<json::StringBuffer>* writer, Usuario* usr)
{
	writer->StartObject();
	writer->Key("codigo");
	writer->Uint(usr->codigo);
	writer->Key("login");
	writer->String(usr->login.c_str());
	writer->Key("nome");
	writer->String(usr->nome.c_str());
	writer->Key("perfil");
	writer->String(usr->perfil.c_str());
	writer->EndObject();
}

void UsuarioSerializer::serializeUsuarioList(json::Writer<json::StringBuffer>* writer, std::vector<Usuario*> usuarios)
{
	writer->StartArray();
	
	for(auto const& usuario: usuarios) 
		serialize(writer, (Usuario*) usuario);
		
	writer->EndArray();
}