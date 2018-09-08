#include "src/headers/controls/SensorControl.h"

#include "src/headers/database/dao/DAOSensores.h"
#include "src/headers/json/serializer/SensorSerializer.h"

SensorControl* SensorControl::m_This = NULL;

SensorControl* SensorControl::GetControl()
{
	if(m_This == NULL)
		m_This = new SensorControl();
		
	return m_This;
}

void SensorControl::ListarTodos(crow::response* response_)
{
		json::StringBuffer buffer;
		PrettyWriter<StringBuffer> writer(buffer);
		
		SensorSerializer::GetSerializer()->serializeSensorList(&writer, DAOSensores::GetDAO()->GetSensores());
		response_->write(buffer.GetString());
}

void SensorControl::ListarPorCodigoComodo(crow::response* response_, int comodo)
{
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	SensorSerializer::GetSerializer()->serializeSensorList(&writer, DAOSensores::GetDAO()->GetSensorPorComodo((uint16_t) comodo));
	response_->write(buffer.GetString());
}