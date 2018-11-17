#include "headers/json/serializer/ComodoSerializer.h"

ComodoSerializer* ComodoSerializer::m_This = NULL;

ComodoSerializer* ComodoSerializer::GetSerializer()
{
	if(m_This == NULL)
		m_This = new ComodoSerializer();
		
	return m_This;
}

void ComodoSerializer::serializeComodo(rapidjson::Writer<rapidjson::StringBuffer>* writer, Comodo* com)
{
	writer->StartObject();
	writer->Key("idComodo");
	writer->Uint(com->codigo);
	writer->Key("nome");
	writer->String(com->nome.c_str());
	writer->Key("Tipo");
	writer->Uint(com->tipo);
	writer->Key("Externo");
	writer->Bool(com->externo);
	writer->EndObject();
}

void ComodoSerializer::serializeComodoList(rapidjson::Writer<rapidjson::StringBuffer>* writer, std::vector<Comodo*> comodos)
{
	writer->StartArray();
	
	for(auto const& comodo: comodos) 
		serializeComodo(writer, (Comodo*) comodo);
		
	writer->EndArray();
}

Comodo* ComodoSerializer::parse(const std::string json)
{
	rapidjson::Document document;
	document.Parse(json.c_str());
	
	CLogger::GetLogger()->Log(json.c_str());
	
	Comodo* comodo = new Comodo();
	
	if(document.HasMember("nome"))
	{
		comodo->nome = document["nome"].GetString();
	}
	
	if(document.HasMember("tipo"))
	{
		comodo->tipo = document["tipo"].GetInt();
	}
	
	if(document.HasMember("externo"))
	{
		comodo->externo = document["externo"].GetInt();
	}
	
	CLogger::GetLogger()->Log(comodo->nome.c_str());
	
	return comodo;
}