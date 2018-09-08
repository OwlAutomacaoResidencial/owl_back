#ifndef DAO_SENSORES
#define DAO_SENSORES

#include "src/headers/database/mysql_manager.h"
#include "src/headers/sensores/sensor.h"

#include <vector>

sql::ResultSet* GetAllSensores(sql::Connection* con);

static Sensor* m_Sensores[2] = {
	new Sensor
	{
	.codigo = 1,
	.nome = "Luz da Sala",
	.codigoComodo = 1
	},
	new Sensor
	{
	.codigo = 2,
	.nome = "Luz da Cozinha",
	.codigoComodo = 2
	}};
	
class DAOSensores
{
public:
	static DAOSensores* GetDAO();
	static std::vector<Sensor*> GetSensores();
	std::vector<sensor*> GetSensorPorComodo(uint16_t codigoComodo);
private:
	static DAOSensores* m_This;
	static std::vector<Sensor*> mockSensor;
	void InicializaMock();
};

#endif