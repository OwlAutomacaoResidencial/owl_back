#ifndef COMODOSERIALIZER
#define COMODOSERIALIZER

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <cppconn/resultset.h>
#include "src/headers/comodos/comodo.h"

#include <vector>

namespace json = rapidjson;

class ComodoSerializer
{
public:
	static ComodoSerializer* GetSerializer();
	void serializeComodo(json::Writer<json::StringBuffer>* writer, Comodo* com);
	void serializeComodoList(json::Writer<json::StringBuffer>* writer, std::vector<Comodo*> comodos);
private:
	static ComodoSerializer* m_This;
};

#endif