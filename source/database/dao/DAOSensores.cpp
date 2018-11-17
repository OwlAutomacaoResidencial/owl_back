#include "headers/database/dao/DAOSensores.h"

static void inicializaTipoSensores() 
{
	tipo_sensores.push_back(new t_sensor
	{
		.codigo = 1,
		.descricao = "Teste"
	});
}

DAOSensores* DAOSensores::m_This = NULL;

DAOSensores* DAOSensores::GetDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOSensores();
		inicializaTipoSensores();
	}
	return m_This;
}

t_sensor* DAOSensores::getTipoSensor(int tipo)
{
	for(auto const& tipoSensor: tipo_sensores)
	{
		t_sensor* t = (t_sensor*) tipoSensor;
		if(t->codigo == tipo)
		{
			return t;
		}
	}
	return NULL;
}

const std::vector<sensor*> DAOSensores::GetSensorPorComodo(uint16_t codigoComodo)
{
	std::vector<sensor*> listaRetorno;
	std::vector<sensor*>::iterator it;
	
	it = listaRetorno.begin();
	
	/*for(auto const& sensor: mockSensor)
	{
		Sensor* sensr = (Sensor*) sensor;
		
		if(sensr->codigoComodo == codigoComodo)
			it = listaRetorno.insert(it, sensr);
	}*/

	return listaRetorno;
}

const std::vector<Sensor*> DAOSensores::GetSensores()
{
	std::vector<Sensor*> retorno;
	std::vector<sensor*>::iterator it;
	
	it = retorno.begin();
	
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select * from sensor");
	rs = prep_stmt->executeQuery();
	
	while(rs->next()) 
	{
		Sensor* sensor_ = new Sensor();
		sensor_->codigo = rs->getInt("idSensor");
		sensor_->nome = rs->getString("nomeSensor");
		sensor_->tipo = getTipoSensor(rs->getInt("tipo"));

		it = retorno.insert(it, sensor_);
	}
	
	delete prep_stmt;
	delete rs;
	
	return retorno;
}