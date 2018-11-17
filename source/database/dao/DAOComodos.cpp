#include "headers/database/dao/DAOComodos.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
#include "headers/logging/Logger.h"

DAOComodo* DAOComodo::m_This = NULL;
std::vector<Comodo*> DAOComodo::mockComodos;

DAOComodo* DAOComodo::GetDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOComodo();
		m_This->InicializaMock();
	}
	return m_This;
}

std::vector<Comodo*> DAOComodo::GetComodosPorUsuario(uint16_t codigo_usuario)
{
	std::vector<Comodo*> result;
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	CLogger::GetLogger()->Log("Retreving Comod of User %d", codigo_usuario);
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select idComodo from usuarioComodo where idUsuario = ?");
	prep_stmt->setInt(1, codigo_usuario);
	rs = prep_stmt->executeQuery();
	
	while (rs->next())
	{
		result.push_back(m_This->RecuperarPorCodigo(rs->getInt("idComodo")));
	}
	
	delete prep_stmt;
	delete rs;
	
	return result;
}

Comodo* DAOComodo::RecuperarPorCodigo(uint16_t codigo)
{
	std::vector<Comodo*> result;
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select * from comodo where idComodo = ?;");
	prep_stmt->setInt(1, codigo);
	rs = prep_stmt->executeQuery();
	
	if (rs->next())
	{
		Comodo* comod = new Comodo();
		comod->codigo = rs->getInt("idComodo");
		comod->nome = rs->getString("nome").c_str();
		comod->tipo = rs->getInt("tipo");
		comod->externo = rs->getInt("externo");
		
		delete prep_stmt;
		delete rs;
		
		return comod;
	}
	
	delete prep_stmt;
	delete rs;
	
	return NULL;
}

std::vector<Comodo*> DAOComodo::GetComodos()
{
	std::vector<Comodo*> result;
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select * from comodo;");
	rs = prep_stmt->executeQuery();
	
	while (rs->next())
	{
		Comodo* comod = new Comodo();
		comod->codigo = rs->getInt("idComodo");
		comod->nome = rs->getString("nome").c_str();
		comod->tipo = rs->getInt("tipo");
		comod->externo = rs->getInt("externo");
		
		result.push_back(comod);
	}
	
	delete prep_stmt;
	delete rs;
	
	return result;
}

Comodo* DAOComodo::Create(Comodo* comodo)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to create comodo %s %d %d", comodo->nome.c_str(), comodo->tipo, comodo->externo);
	
	std::stringstream query;
	query << "INSERT INTO comodo (nome, tipo, externo) VALUES ";
	query << "(?,?,?);";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setString(1, comodo->nome);
		prep_stmt->setInt(2, comodo->tipo);
		prep_stmt->setInt(3, (int) comodo->externo);
		prep_stmt->executeUpdate();	
		
		comodo->codigo = MySQLConnector::getManager()->returnGeneratedId(conn);
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
	
	return comodo;
}


void DAOComodo::del(int idcomodo)
{
	sql::Connection *conn = MySQLConnector::getManager()->getConnection();
	sql::PreparedStatement  *prep_stmt;
	
	conn->setAutoCommit(false);
	
	CLogger::GetLogger()->Log("Trying to delete comodo %d", idcomodo);
	
	std::stringstream query;
	query << "DELETE FROM comodo WHERE idcomodo = ? ";
	
	try {
		prep_stmt = conn->prepareStatement(query.str());
		prep_stmt->setInt(1, idcomodo);
		prep_stmt->executeUpdate();
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	conn->commit();
	
	delete prep_stmt;
}

void DAOComodo::InicializaMock()
{
	mockComodos.push_back(new Comodo
	{
		.codigo = 1,
		.nome = "Sala",
		.tipo = 1,
		.externo = false
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 2,
		.nome = "Cozinha",
		.tipo = 2,
		.externo = false
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 3,
		.nome = "Escritório",
		.tipo = 3,
		.externo = false
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 4,
		.nome = "Quarto 1",
		.tipo = 4,
		.externo = false
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 5,
		.nome = "Jardim",
		.tipo = 5,
		.externo = true
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 6,
		.nome = "Piscina",
		.tipo = 6,
		.externo = true
	});
	
	mockComodos.push_back(new Comodo
	{
		.codigo = 7,
		.nome = "Churrasqueira",
		.tipo = 7,
		.externo = true
	});
}