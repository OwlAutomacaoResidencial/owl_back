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