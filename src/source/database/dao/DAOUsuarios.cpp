#include "src/headers/database/dao/DAOUsuarios.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
 
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
	for(auto const& usuario: mockUsuarios)
	{
		Usuario* usr = (Usuario*) usuario;
		
		if(boost::iequals(usr->login, login) && boost::iequals(usr->senha, passwd))
			return usr;
	}
	
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
