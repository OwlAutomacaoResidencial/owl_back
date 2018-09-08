#include "src/headers/json/serializer/SensorSerializer.h"
#include "src/headers/logging/Logger.h"

SensorSerializer* SensorSerializer::m_This = NULL;

SensorSerializer* SensorSerializer::GetSerializer()
{
	if(m_This == NULL)
		m_This = new SensorSerializer();
		
	return m_This;
}

void SensorSerializer::serializeSensor(json::PrettyWriter<json::StringBuffer>* writer, sql::ResultSet* rs)
{
	writer->StartObject();
	writer->Key("idSensor");
	writer->Int(rs->getInt("idSensor"));
	writer->Key("nome");
	writer->String(rs->getString("nome").c_str());
	writer->Key("ip");
	writer->String(rs->getString("ip").c_str());
	writer->EndObject();
}

void SensorSerializer::serializeSensor(json::PrettyWriter<json::StringBuffer>* writer, Sensor* sen)
{
	if(sen == 0x00 || sen == NULL)
		return;
	
	writer->StartObject();
	writer->Key("idSensor");
	writer->Uint(sen->codigo);
	writer->Key("nome");
	writer->String(sen->nome.c_str());
	writer->Key("ip");
	writer->String(sen->ip.c_str());
	
	Comodo* comodo = DAOComodo::GetDAO()->RecuperarPorCodigo(sen->codigoComodo);
	
	if(comodo != NULL)
	{
		writer->Key("Comodo");
		ComodoSerializer::GetSerializer()->serializeComodo(writer, comodo);
	}
	
	if(sen->tipo != NULL)
	{
		writer->Key("Tipo");
		writer->StartObject();
		writer->Key("codigo");
		writer->Uint(sen->tipo->codigo);
		writer->Key("descricao");
		writer->String(sen->tipo->descricao.c_str());
		writer->EndObject();
	}
	
	writer->Key("index");
	writer->Uint(sen->index);
	
	writer->EndObject();
}

void SensorSerializer::serializeSensorList(json::PrettyWriter<json::StringBuffer>* writer, sql::ResultSet* rs)
{
	writer->StartArray();
	
	while(rs->next())
		serializeSensor(writer, rs);
		
	writer->EndArray();
}

void SensorSerializer::serializeSensorList(json::PrettyWriter<json::StringBuffer>* writer, std::vector<Sensor*> sensores)
{
	writer->StartArray();
	
	for(auto const& value: sensores) 
		serializeSensor(writer, (Sensor*) value);

	writer->EndArray();
}