#include "headers/controls/OcorrenciasControl.h"

#include "headers/database/dao/DAOOcorrencias.h"

#include "headers/json/serializer/OcorrenciaSerializer.h"

OcorrenciaControl* OcorrenciaControl::m_This = NULL;

OcorrenciaControl* OcorrenciaControl::getControl()
{
	if(m_This == NULL)
		m_This = new OcorrenciaControl();
	return m_This;
}

crow::response OcorrenciaControl::listarTodos()
{
	crow::response response_ = crow::response(200);
	
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	OcorrenciaSerializer::getSerializer()->serializeOcorrenciaList(&writer, DAOOcorrencias::getDAO()->getOcorrencias());
	response_.write(buffer.GetString());
	
	return response_;
}