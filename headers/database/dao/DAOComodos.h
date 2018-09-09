#ifndef DAO_COMODOS
#define DAO_COMODOS

#include "headers/database/mysql_manager.h"
#include "headers/comodos/comodo.h"

#include <vector>

sql::ResultSet* GetAllComodos(sql::Connection* con);
	
class DAOComodo
{
public:
	static DAOComodo* GetDAO();
	static std::vector<Comodo*> GetComodos();
	std::vector<Comodo*> GetComodosPorUsuario(uint16_t codigo_usuario);
	Comodo* RecuperarPorCodigo(uint16_t codigo);
private:
	static DAOComodo* m_This;
	static std::vector<Comodo*> mockComodos;
	void InicializaMock();
};

#endif