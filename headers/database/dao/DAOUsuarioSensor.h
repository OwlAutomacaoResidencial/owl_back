#ifndef DAO_USUARIO_SENSORES
#define DAO_USUARIO_SENSORES

#include "headers/database/mysql_manager.h"

#include "headers/logging/Logger.h"

#include <string>
#include <sstream>
#include <vector>

class DAOUsuarioSensor
{
public:
	static DAOUsuarioSensor* getDAO();
	void create(int idUsuario, int idSensor);
	void del(int idUsuario, int idSensor);
private:
	static DAOUsuarioSensor* m_This;
};

#endif