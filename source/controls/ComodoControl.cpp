#include "../../headers/controls/ComodoControl.h"
#include "../../headers/database/dao/DAOComodos.h"

#include "headers/json/serializer/ComodoSerializer.h"

ComodoControl* ComodoControl::m_This = NULL;

ComodoControl* ComodoControl::GetControl()
{
	if(m_This == NULL)
		m_This = new ComodoControl();
	return m_This;
}

void ComodoControl::ListarTodos(crow::response* response_)
{
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	ComodoSerializer::GetSerializer()->serializeComodoList(&writer, DAOComodo::GetDAO()->GetComodos());
	response_->write(buffer.GetString());
}

crow::response ComodoControl::create(std::string json)
{
	Comodo* comodo = ComodoSerializer::GetSerializer()->parse(json);
	
	comodo = DAOComodo::GetDAO()->Create(comodo);
	
	CLogger::GetLogger()->Log("%d %s %d %d", comodo->codigo, comodo->nome, 
	comodo->tipo, comodo->externo);
	
	crow::response response_ = crow::response(200);
	
	json::StringBuffer buffer;
	json::PrettyWriter<json::StringBuffer> writer(buffer);
	
	try {
		ComodoSerializer::GetSerializer()->serializeComodo(&writer, comodo);
		response_.write(buffer.GetString());	
	}
	catch(const std::exception& exc) {
		cerr << exc.what();
	}
	
	return response_;
}

crow::response ComodoControl::del(int idcomodo)
{
	DAOComodo::GetDAO()->del(idcomodo);
	
	return crow::response(200);
}