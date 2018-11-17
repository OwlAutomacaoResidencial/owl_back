#ifndef COMODOSERIALIZER
#define COMODOSERIALIZER

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <cppconn/resultset.h>
#include "headers/comodos/comodo.h"

#include "headers/logging/Logger.h"

#include <string>
#include <vector>

class ComodoSerializer
{
public:
	static ComodoSerializer* GetSerializer();
	void serializeComodo(rapidjson::Writer<rapidjson::StringBuffer>* writer, Comodo* com);
	void serializeComodoList(rapidjson::Writer<rapidjson::StringBuffer>* writer, std::vector<Comodo*> comodos);
	
	Comodo* parse(const std::string json);
private:
	static ComodoSerializer* m_This;
};

#endif