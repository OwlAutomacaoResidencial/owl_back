#include "headers/json/serializer/MWebSessionSerializer.h"

MWebSessionSerializer* MWebSessionSerializer::m_This = NULL;

MWebSessionSerializer* MWebSessionSerializer::GetSerializer()
{
	if(m_This == NULL)
		m_This = new MWebSessionSerializer();
		
	return m_This;
}

void MWebSessionSerializer::serialize(json::Writer<json::StringBuffer>* writer, MWebSession* session)
{
	writer->StartObject();
	writer->Key("token");
	writer->String(session->token.c_str());
	
	writer->Key("Usuario");
	UsuarioSerializer::GetSerializer()->serialize(writer, session->usuario);
	
	writer->EndObject();
}