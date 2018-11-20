#include "headers/controls/UsuarioSensorControl.hpp"

#include "headers/database/dao/DAOUsuarioSensor.h"
#include "headers/json/serializer/SensorSerializer.h"

#include "headers/logging/Logger.h"

UsuarioSensorControl* UsuarioSensorControl::m_This = NULL;

UsuarioSensorControl* UsuarioSensorControl::GetControl()
{
	if(m_This == NULL)
		m_This = new UsuarioSensorControl();
		
	return m_This;
}

crow::response UsuarioSensorControl::create(int idUsuario, int idSensor)
{
	DAOUsuarioSensor::getDAO()->create(idUsuario, idSensor);
	
	return crow::response(200);
}

crow::response UsuarioSensorControl::del(int idUsuario, int idSensor)
{
	DAOUsuarioSensor::getDAO()->del(idUsuario, idSensor);
	
	return crow::response(200);
}

crow::response UsuarioSensorControl::listar(int idUsuario)
{
	crow::response response_ = crow::response(200);
	
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	SensorSerializer::GetSerializer()->serializeSensorList(&writer, DAOUsuarioSensor::getDAO()->GetSensores(idUsuario));
	response_.write(buffer.GetString());
	
	return response_;
}