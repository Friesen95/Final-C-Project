#include "Storage.h"

using namespace std;

Storage::Storage()
{
	driver = get_driver_instance();
}

// Gets player by id, first name and lastname
void Storage::getPlayer(Player& p)
{
	connect();

	stmt = con->createStatement();

	queryString.append("SELECT * FROM Players WHERE ");
	queryString.append(p.getId() != -1 ? "id = " + to_string(p.getId()) + " " : "");
	queryString.append(p.getFirstName() != "" ? "AND firstName = '" + p.getFirstName() + "' " : "");
	queryString.append(p.getLastName() != "" ? "AND lastName = '" + p.getLastName() + "'" : "");

	res = stmt->executeQuery(queryString);

	while (res->next())
	{
		// Update the player reference
		p.setId(stoi(res->getString("id")));
		p.setLastName(res->getString("LastName"));
		p.setFirstName(res->getString("firstName"));
	}

	res->close();
	disconnect();
}

void Storage::printAllPlayers()
{
	connect();

	stmt = con->createStatement();
	queryString.append("SELECT * FROM Players");
	res = stmt->executeQuery(queryString);

	while (res->next()) 
	{
		cout << "First Name: " << res->getString("firstName") << " "; 
		cout << ", Last Name: " << res->getString("lastName") << endl;
	}

	res->close();
	disconnect();
}

void Storage::createPlayer(Player& newPlayer)
{
	int error;
	connect();

	stmt = con->createStatement();
	error = stmt->executeUpdate("INSERT INTO Players(firstName, lastName) VALUES('Andriy', 'Shevchenko')");

	disconnect();
}


void Storage::connect()
{
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
	con->setSchema("cppfinal");
	queryString = "";
}

void Storage::disconnect()
{
	queryString = "";
	stmt->close();
	con->close();
}

void Storage::seedDb()
{

}