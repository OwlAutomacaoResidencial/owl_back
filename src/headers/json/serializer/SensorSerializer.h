#ifndef SENSOR_SERIALIZER
#define SENSOR_SERIALIZER

#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <cppconn/resultset.h>
#include "src/headers/sensores/sensor.h"

#include "src/headers/json/serializer/ComodoSerializer.h"
#include "src/headers/database/dao/DAOComodos.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <vector>

namespace json = rapidjson;

class SensorSerializer
{
public:
	static SensorSerializer* GetSerializer();
	void serializeSensor(json::PrettyWriter<json::StringBuffer>* writer, sql::ResultSet* rs);
	void serializeSensor(json::PrettyWriter<json::StringBuffer>* writer, Sensor* sen);
	void serializeSensorList(json::PrettyWriter<json::StringBuffer>* writer, sql::ResultSet* rs);
	void serializeSensorList(json::PrettyWriter<json::StringBuffer>* writer, std::vector<Sensor*> sensores);
private:
	static SensorSerializer* m_This;
};

#endif