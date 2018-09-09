#ifndef MYSQL_CONNECTOR_MANAGER
#define MYSQL_CONNECTOR_MANAGER

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#define MYSQL_HOST "tcp://127.0.0.1:3306"
#define MYSQL_USERNAME "owl"
#define MYSQL_PASSWORD "owl"
#define MYSQL_SCHEMA "owl"

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