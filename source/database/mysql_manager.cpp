#include "headers/database/mysql_manager.h"

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
	sql::Connection* conn = driver->connect(MYSQL_HOST, MYSQL_USERNAME, MYSQL_PASSWORD);
	conn->setSchema(MYSQL_SCHEMA);
	return conn;
}

int MySQLConnector::returnGeneratedId(sql::Connection *conn)
{
	sql::ResultSet *rs;
	int generatedId;
	
	try {
		rs = conn->prepareStatement("SELECT LAST_INSERT_ID()")->executeQuery();
		rs->first();
		generatedId = rs->getInt(1);
		
		delete rs;	
	} catch (std::exception& e) {
		std::cerr << "Exception catched : " << e.what() << std::endl;
	}
	
	return generatedId;
}