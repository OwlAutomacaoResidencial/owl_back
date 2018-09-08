#include "src/headers/database/dao/DAOSensores.h"

DAOSensores* DAOSensores::m_This = NULL;
std::vector<Sensor*> DAOSensores::mockSensor;

DAOSensores* DAOSensores::GetDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOSensores();	
		m_This->InicializaMock();
	}
	return m_This;
}

sql::ResultSet* GetAllSensores(sql::Connection *con)
{
	sql::Statement *stmt;
	sql::ResultSet *res;
	
	con->setSchema("homeon");

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM SENSOR");
	
	return res;
}

std::vector<sensor*> DAOSensores::GetSensorPorComodo(uint16_t codigoComodo)
{
	std::vector<sensor*> listaRetorno;
	std::vector<sensor*>::iterator it;
	
	it = listaRetorno.begin();
	
	for(auto const& sensor: mockSensor)
	{
		Sensor* sensr = (Sensor*) sensor;
		
		if(sensr->codigoComodo == codigoComodo)
			it = listaRetorno.insert(it, sensr);
	}

	return listaRetorno;
}

std::vector<Sensor*> DAOSensores::GetSensores()
{
	return mockSensor;
}

void DAOSensores::InicializaMock()
{
	TipoSensor* tipoSensorLampada = new TipoSensor;
	tipoSensorLampada->codigo = 1;
	tipoSensorLampada->descricao = "Lâmpada";
	
	mockSensor.push_back(new Sensor
	{
		.codigo = 43775,
		.nome = "Luz da TV",
		.codigoComodo = 1,
		.ip = "192.168.0.10",
		.tipo = tipoSensorLampada,
		.index = 1
	});
	
	mockSensor.push_back(new Sensor
	{
		.codigo = 43775,
		.nome = "Luz do Sofá",
		.codigoComodo = 1,
		.ip = "192.168.0.11",
		.tipo = tipoSensorLampada,
		.index = 2
	});
	
	mockSensor.push_back(new Sensor
	{
		.codigo = 43775,
		.nome = "Luz da Cozinha",
		.codigoComodo = 2,
		.ip = "192.168.0.12",
		.tipo = tipoSensorLampada,
		.index = 3
	});
}