#pragma once
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class Storage
{
public:
	Storage();
	void connectToDb();
	void seedDb();
private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
};

