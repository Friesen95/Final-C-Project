#include "Storage.h"

using namespace std;

Storage::Storage()
{
	driver = get_driver_instance();
}

// Prints out all players
void Storage::printAllPlayers()
{
	connect();

	queryString.append("SELECT * FROM Players");
	res = stmt->executeQuery(queryString);

	while (res->next())
	{
		cout << "First Name: " << res->getString("firstName") << " ";
		cout << ", Last Name: " << res->getString("lastName") << endl;
	}

	res->close();
	delete res;
	disconnect();
}

// Gets a player by id, first name and lastname
// Need to fix the where clause!
void Storage::getPlayer(Player& p)
{
	connect();

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
	delete res;
	disconnect();
}

void Storage::createPlayer(Player& newPlayer)
{
	int error;
	connect();

	error = stmt->executeUpdate("INSERT INTO Players(firstName, lastName) VALUES('Andriy', 'Shevchenko')");

	disconnect();
}

void Storage::updatePlayer(Player& updatedPlayer)
{
	int error;
	connect();

	queryString.append("UPDATE Players SET firstName = '");
	queryString.append(updatedPlayer.getFirstName());
	queryString.append("' WHERE id = ");
	queryString.append(to_string(updatedPlayer.getId()));

	error = stmt->executeUpdate(queryString);

	disconnect();
}

void Storage::deletePlayer(Player& deletedPlayer)
{
	int error;
	connect();

	queryString.append("DELETE FROM Players WHERE id = ");
	queryString.append(to_string(deletedPlayer.getId()));

	error = stmt->executeUpdate(queryString);

	disconnect();
}


void Storage::connect()
{
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
	con->setSchema("cppfinal");
	stmt = con->createStatement();
	queryString = "";
}

void Storage::disconnect()
{
	queryString = "";
	stmt->close();
	delete stmt;
	con->close();
	delete con;
}

void Storage::seedDb()
{

}