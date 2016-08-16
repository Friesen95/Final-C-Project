#pragma once
#include "Player.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class Storage
{
public:
	Storage();
	void printAllPlayers();
	bool getPlayer(Player&);
	void createPlayer(Player&);
	void updatePlayer(Player&);
	void deletePlayer(Player&);
	void seedDb();
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::ResultSet* res;
	std::string queryString;
	void connect();
	void disconnect();
};

