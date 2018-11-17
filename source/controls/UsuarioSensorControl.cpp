#include "headers/controls/UsuarioSensorControl.hpp"

#include "headers/database/dao/DAOUsuarioSensor.h"

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