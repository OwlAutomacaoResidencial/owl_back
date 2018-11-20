#include "headers/database/dao/DAOUsuarioSensor.h"

#include <string.h>
#include <boost/algorithm/string.hpp>

DAOUsuarioSensor* DAOUsuarioSensor::m_This = NULL;

DAOUsuarioSensor* DAOUsuarioSensor::getDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOUsuarioSensor();
	}
	return m_This;
}

void DAOUsuarioSensor::create(int idUsuario, int idSensor)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to create usuario sensor %d %d", idUsuario, idSensor);
	
	std::stringstream query;
	query << "INSERT INTO usuarioSensor (idUsuario, idSensor) VALUES ";
	query << "(?,?);";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setInt(1, idUsuario);
		prep_stmt->setInt(2, idSensor);
		prep_stmt->executeUpdate();	
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
}

void DAOUsuarioSensor::del(int idUsuario, int idSensor)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to delete usuarioSensor %d %d", idUsuario, idSensor);
	
	std::stringstream query;
	query << "DELETE FROM usuarioSensor WHERE idUsuario = ? and idSensor = ? ";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setInt(1, idUsuario);
		prep_stmt->setInt(2, idSensor);
		prep_stmt->executeUpdate();
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
}

const std::vector<Sensor*> DAOUsuarioSensor::GetSensores(int idUsuario)
{
	std::vector<Sensor*> retorno;
	std::vector<sensor*>::iterator it;
	
	it = retorno.begin();
	
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select sensor.* from usuarioSensor inner join sensor ON sensor.idSensor = usuarioSensor.idSensor where idUsuario = ?");
	prep_stmt->setInt(1, idUsuario);
	rs = prep_stmt->executeQuery();
	
	while(rs->next()) 
	{
		Sensor* sensor_ = new Sensor();
		sensor_->codigo = rs->getInt("idSensor");
		sensor_->nome = rs->getString("nomeSensor");
		sensor_->tipo = DAOSensores::GetDAO()->getTipoSensor(rs->getInt("tipo"));

		it = retorno.insert(it, sensor_);
	}
	
	delete prep_stmt;
	delete rs;
	
	return retorno;
}