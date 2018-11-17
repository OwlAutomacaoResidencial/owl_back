#ifndef SENSOR_SERIALIZER
#define SENSOR_SERIALIZER

#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <cppconn/resultset.h>
#include "headers/sensores/sensor.h"

#include "headers/json/serializer/ComodoSerializer.h"
#include "headers/database/dao/DAOComodos.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <vector>

class SensorSerializer
{
public:
	static SensorSerializer* GetSerializer();
	void serializeSensor(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, sql::ResultSet* rs);
	void serializeSensor(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, Sensor* sen);
	void serializeSensorList(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, sql::ResultSet* rs);
	void serializeSensorList(rapidjson::PrettyWriter<rapidjson::StringBuffer>* writer, std::vector<Sensor*> sensores);
private:
	static SensorSerializer* m_This;
};

#endif