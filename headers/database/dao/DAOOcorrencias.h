#ifndef DAO_OCORRENCIAS
#define DAO_OCORRENCIAS


#include "headers/database/mysql_manager.h"
#include "headers/ocorrencias/ocorrencia.h"

#include <string>
#include <sstream>
#include <vector>

class DAOOcorrencias
{
public:
	static DAOOcorrencias* getDAO();
	static std::vector<Ocorrencia*> getOcorrencias();
	Ocorrencia* Create(Ocorrencia* ocorrencia);
private:
	static DAOOcorrencias* m_This;
};

#endif