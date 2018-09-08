#include "../../headers/controls/ComodoControl.h"
#include "../../headers/database/dao/DAOComodos.h"

#include "src/headers/json/serializer/ComodoSerializer.h"

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