#include "src/headers/database/datasheet.h"

DATA_SHEET* DATA_SHEET::m_This = NULL;

DATA_SHEET* DATA_SHEET::GetDataSheet()
{
	if(m_This == NULL)
		m_This = new DATA_SHEET();
		
	return m_This;
}