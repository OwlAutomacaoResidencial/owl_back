#include "headers/json/serializer/UsuarioSerializer.h"

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

Usuario* UsuarioSerializer::parse(std::string json)
{
	json::Document document;
	document.Parse(json.c_str());
	
	Usuario* user = new Usuario();
	
	if(document.HasMember("email"))
	{
		user->email = document["email"].GetString();
	}
	
	if(document.HasMember("senha"))
	{
		user->senha = document["senha"].GetString();
	}
	
	if(document.HasMember("nome"))
	{
		user->nome = document["nome"].GetString();
	}
	
	if(document.HasMember("perfil"))
	{
		user->perfil = document["perfil"].GetString();
	}
	
	if(document.HasMember("cpf"))
	{
		user->cpf = document["cpf"].GetString();
	}
	
	if(document.HasMember("rg"))
	{
		user->rg = document["rg"].GetString();
	}
	
	if(document.HasMember("dataNascimento"))
	{
		user->dataNascimento = document["dataNascimento"].GetString();
	}
	
	return user;
}