#ifndef DAO_USUARIO_COMODOS
#define DAO_USUARIO_COMODOS

#include "headers/database/mysql_manager.h"
#include "headers/comodos/comodo.h"

#include <string>
#include <sstream>
#include <vector>

class DAOUsuarioComodo
{
public:
	static DAOUsuarioComodo* getDAO();
	void create(int idUsuario, int idComodo);
	void del(int idUsuario, int idComodo);
private:
	static DAOUsuarioComodo* m_This;
};

#endif