#include "headers/database/dao/DAOUsuarioComodo.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
#include "headers/logging/Logger.h"

DAOUsuarioComodo* DAOUsuarioComodo::m_This = NULL;

DAOUsuarioComodo* DAOUsuarioComodo::getDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOUsuarioComodo();
	}
	return m_This;
}

void DAOUsuarioComodo::create(int idUsuario, int idComodo)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to create usuario comodo %d %d", idUsuario, idComodo);
	
	std::stringstream query;
	query << "INSERT INTO usuarioComodo (idUsuario, idComodo) VALUES ";
	query << "(?,?);";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setInt(1, idUsuario);
		prep_stmt->setInt(2, idComodo);
		prep_stmt->executeUpdate();	
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
}


void DAOUsuarioComodo::del(int idUsuario, int idComodo)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to delete usuarioComodo %d %d", idUsuario, idComodo);
	
	std::stringstream query;
	query << "DELETE FROM usuarioComodo WHERE idUsuario = ? and idComodo = ? ";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setInt(1, idUsuario);
		prep_stmt->setInt(2, idComodo);
		prep_stmt->executeUpdate();
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
}