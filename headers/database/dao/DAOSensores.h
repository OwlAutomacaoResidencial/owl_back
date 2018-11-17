#ifndef DAO_SENSORES
#define DAO_SENSORES

#include "headers/database/mysql_manager.h"
#include "headers/sensores/sensor.h"

#include <vector>

class DAOSensores
{
public:
	static DAOSensores* GetDAO();
	
	t_sensor* getTipoSensor(int tipo);
	const std::vector<Sensor*> GetSensores();
	const std::vector<sensor*> GetSensorPorComodo(uint16_t codigoComodo);
private:
	static DAOSensores* m_This;
};

#endif