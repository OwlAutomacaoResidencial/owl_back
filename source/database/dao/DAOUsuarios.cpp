#include "headers/database/dao/DAOUsuarios.h"
#include "headers/database/mysql_manager.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
#include <cppconn/prepared_statement.h>
#include "headers/logging/Logger.h"
 
DAOUsuario* DAOUsuario::m_This = NULL;
std::vector<Usuario*> DAOUsuario::mockUsuarios;

DAOUsuario* DAOUsuario::GetDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOUsuario();
		m_This->InicializaMock();
	}
	return m_This;
}

Usuario* DAOUsuario::Login(std::string login, std::string passwd)
{
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	CLogger::GetLogger()->Log("Trying to login with %s", login.c_str());
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select * from usuario where email = ?");
	prep_stmt->setString(1, login);
	rs = prep_stmt->executeQuery();
	
	if (rs->first()) 
	{
		std::string password = rs->getString("senha");
		
		if (password.compare(passwd) == 0)
		{
			CLogger::GetLogger()->Log("Found user %s, returning", login.c_str());
			//Usuario* usr = static_cast<Usuario*>(malloc(sizeof(Usuario)));
			Usuario* usr = new Usuario();
			usr->codigo = rs->getInt("idUsuario");
			//usr->login = rs->getString("login");
			return usr;	
		}
		else
		{
			CLogger::GetLogger()->Log("Found user %s, invalid password", login.c_str());
		}
	}
	CLogger::GetLogger()->Log("User %s not found", login.c_str());
	
	return NULL;
}

std::vector<Usuario*> DAOUsuario::GetUsuarios()
{
	return mockUsuarios;
}

void DAOUsuario::InicializaMock()
{
	mockUsuarios.push_back(new Usuario
	{
		.codigo = 2,
		.login = "lucas",
		.senha = "1234",
		.perfil = "Visitante",
		.nome = "Lucas Leite"
	});

	mockUsuarios.push_back(new Usuario
	{
		.codigo = 1,
		.login = "missura",
		.senha = "1234",
		.perfil = "Dono",
		.nome = "Douglas Missura"
	});
}
