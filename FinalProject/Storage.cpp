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
		cout << "Player #" << res->getString("id") << ": " 
			<< res->getString("firstName") << " "
			<< res->getString("lastName") << " | " 
			<< res->getString("dateOfBirth") << endl;
	}

	res->close();
	delete res;
	disconnect();
}

// Gets a player by id, first name and lastname
bool Storage::getPlayer(Player& p)
{
	connect();

	//Build querystring - dependant on which information the user inputs
	queryString.append("SELECT * FROM Players WHERE ");
	queryString.append(p.getId() != -1 ? "id = " + to_string(p.getId()) + " " : "");
	queryString.append(p.getId() != -1 && p.getFirstName() != "" ? "AND " : "");
	queryString.append(p.getFirstName() != "" ? "firstName = '" + p.getFirstName() + "' " : "");
	queryString.append((p.getId() != -1 || p.getFirstName() != "") && p.getLastName() != "" ? "AND " : "");
	queryString.append(p.getLastName() != "" ? "lastName = '" + p.getLastName() + "' " : "");

	res = stmt->executeQuery(queryString);

	// If result set is empty, inform caller
	if (res->rowsCount() == 0)
	{
		return false;
	}
	else
	{
		//Display all players that meet the search criteria
		while (res->next())
		{
			// Update the player reference
			p.setId(stoi(res->getString("id")));
			p.setLastName(res->getString("LastName"));
			p.setFirstName(res->getString("firstName"));
			p.setDateOfBirth(res->getString("dateOfBirth"));
			//Print player to screen
			cout << "Player #" << p.getId() << ": " 
				<< p.getFirstName() << " " 
				<< p.getLastName() << " | " 
				<< p.getDateOfBirth() << endl;
		}

	}

	res->close();
	delete res;
	disconnect();
	return true;
}

void Storage::createPlayer(Player& newPlayer)
{
	int error;
	connect();

	queryString.append("INSERT INTO Players(firstName, lastName, dateofbirth) VALUES('");
	queryString.append(newPlayer.getFirstName() + "', '");
	queryString.append(newPlayer.getLastName() + "', '");
	queryString.append(newPlayer.getDateOfBirth() + "')");

	error = stmt->executeUpdate(queryString);

	disconnect();
}

void Storage::updatePlayer(Player& updatedPlayer)
{
	int error;
	connect();

	queryString.append("UPDATE Players SET firstName = '");
	queryString.append(updatedPlayer.getFirstName());
	queryString.append("', lastName = '");
	queryString.append(updatedPlayer.getLastName());
	queryString.append("', dateOfBirth = '");
	queryString.append(updatedPlayer.getDateOfBirth());
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
	con = driver->connect("tcp://127.0.0.1:3306", "root", "chaoss");
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
	//int error;
	//connect();

	////read seed.sql
	//
	//disconnect();
}