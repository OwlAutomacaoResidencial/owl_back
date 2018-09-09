#include "headers/database/dao/DAOUsuarios.h"
#include "headers/database/mysql_manager.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
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

std::string DAOUsuario::GetPerfil(uint16_t cod_user)
{
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select perfil from usuario where idUsuario = ?");
	prep_stmt->setInt(1, cod_user);
	rs = prep_stmt->executeQuery();
	
	if (rs->first())
	{
		std::string user_perfil = rs->getString("perfil");
		
		delete prep_stmt;
		delete rs;
		
		return user_perfil;
	}
	else
	{
		delete prep_stmt;
		delete rs;
		
		return NULL;
	}
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
			
			delete prep_stmt;
			delete rs;
			return usr;	
		}
		else
		{
			CLogger::GetLogger()->Log("Found user %s, invalid password", login.c_str());
		}
	}
	CLogger::GetLogger()->Log("User %s not found", login.c_str());
	
	delete prep_stmt;
	delete rs;
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
