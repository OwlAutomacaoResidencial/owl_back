#ifndef MWEBSESSIONSERIALIZER_H
#define MWEBSESSIONSERIALIZER_H

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "headers/mweb/MWebSession.h"

#include "headers/json/serializer/UsuarioSerializer.h"

#include <vector>

namespace json = rapidjson;

class MWebSessionSerializer
{
public:
	static MWebSessionSerializer* GetSerializer();
	void serialize(json::Writer<json::StringBuffer>* writer, MWebSession* session);
private:
	static MWebSessionSerializer* m_This;
};

#endif