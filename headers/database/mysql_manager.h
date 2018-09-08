#ifndef MYSQL_CONNECTOR_MANAGER
#define MYSQL_CONNECTOR_MANAGER

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#define MYSQL_HOST "tcp://192.168.0.107:3306"
#define MYSQL_USERNAME "homeon"
#define MYSQL_PASSWORD "homeon123"

class MySQLConnector
{
private:
	MySQLConnector();
	sql::Driver *driver;
	static MySQLConnector *m_this;
public:
	static MySQLConnector *getManager();
	sql::Connection *getConnection();
};



#endif