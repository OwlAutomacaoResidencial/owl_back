#include "src/headers/json/serializer/ComodoSerializer.h"

ComodoSerializer* ComodoSerializer::m_This = NULL;

ComodoSerializer* ComodoSerializer::GetSerializer()
{
	if(m_This == NULL)
		m_This = new ComodoSerializer();
		
	return m_This;
}

void ComodoSerializer::serializeComodo(json::Writer<json::StringBuffer>* writer, Comodo* com)
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

void ComodoSerializer::serializeComodoList(json::Writer<json::StringBuffer>* writer, std::vector<Comodo*> comodos)
{
	writer->StartArray();
	
	for(auto const& comodo: comodos) 
		serializeComodo(writer, (Comodo*) comodo);
		
	writer->EndArray();
}