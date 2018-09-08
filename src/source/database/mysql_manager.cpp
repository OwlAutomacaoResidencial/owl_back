#include "src/headers/database/mysql_manager.h"

MySQLConnector* MySQLConnector::m_this = NULL;

MySQLConnector::MySQLConnector()
{
	driver = get_driver_instance();
}

MySQLConnector *MySQLConnector::getManager()
{
	if(m_this == NULL)
		m_this = new MySQLConnector();
		
	return m_this;
}

sql::Connection *MySQLConnector::getConnection()
{
	return driver->connect(MYSQL_HOST, MYSQL_USERNAME, MYSQL_PASSWORD);
}