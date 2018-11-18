#include "headers/database/dao/DAOOcorrencias.h"

#include <string.h>
#include <boost/algorithm/string.hpp>
#include "headers/logging/Logger.h"

DAOOcorrencias* DAOOcorrencias::m_This = NULL;

DAOOcorrencias* DAOOcorrencias::getDAO()
{
	if(m_This == NULL)
	{
		m_This = new DAOOcorrencias();
	}
	return m_This;
}

std::vector<Ocorrencia*> DAOOcorrencias::getOcorrencias()
{
	std::vector<Ocorrencia*> result;
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet *rs;
	
	prep_stmt = MySQLConnector::getManager()->getConnection()->prepareStatement("select * from ocorrencias;");
	rs = prep_stmt->executeQuery();
	
	while (rs->next())
	{
		Ocorrencia* ocorr = new Ocorrencia();
		ocorr->codigo = rs->getInt("idOcorrencia");
		ocorr->sensor = rs->getString("sensor").c_str();
		ocorr->comodo = rs->getString("comodo").c_str();
		ocorr->dataHora = rs->getString("dataHora").c_str();
		
		result.push_back(ocorr);
	}
	
	delete prep_stmt;
	delete rs;
	
	return result;
	
	CLogger::GetLogger()->Log("Listou no banco");
}