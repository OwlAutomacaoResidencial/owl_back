#include "src/headers/database/dao/DAOComodos.h"

#include <string.h>
#include <boost/algorithm/string.hpp>

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

Comodo* DAOComodo::RecuperarPorCodigo(uint16_t codigo)
{
	for(auto const& comodo: mockComodos) 
	{
		if(((Comodo*) comodo)->codigo == codigo)
			return (Comodo*) comodo;
	}

	return NULL;
}

std::vector<Comodo*> DAOComodo::GetComodos()
{
	return mockComodos;
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