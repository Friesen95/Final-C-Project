/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include "Header.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>

/*
Include directly the different
headers from cppconn/ and mysql_driver.h + mysql_util.h
(and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "chaoss");

	/* Connect to the MySQL test database */
	con->setSchema("test");
	stmt = con->createStatement();

	/*stmt->execute("USE test");
	stmt->execute("DROP TABLE IF EXISTS test");
	stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
	stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");*/

	res = stmt->executeQuery("SELECT id, label FROM test ORDER BY id ASC");
	while (res->next()) {
		// You can use either numeric offsets...
		cout << "id = " << res->getString("id"); // getInt(1) returns the first column
												 // ... or column names for accessing results.
												 // The latter is recommended.
		cout << ", label = '" << res->getString("label") << "'" << endl;
	}

	delete res;
	delete stmt;
	delete con;
	cout << "Done" << endl;
	system("pause");
	return 0;
}
//int main()
//{
//	//PopulateTestData();
//	system("pause");
//	MainMenu();
//
//	system("PAUSE");
//	return 0;
//}
void MainMenu() {
	int choice = 0;
	string message;
	do {
		system("cls");//clear screen
		if (choice == -1)
			message = "Invalid Input. Try again...\n";
		else
			message = "\n";
		cout
			<< "*************************\n"
			<< "*       Main Menu       *\n"
			<< "*************************\n"
			<< "1) Create Player\n"
			<< "2) Edit Player\n"
			<< "3) Delete Player\n"
			<< "4) Print Player\n"
			<< "5) Print Team\n"
			<< "6) Exit\n"
			<< message
			<< "Option: ";
		/**
		*	Get Answer from User
		*/
		cin >> choice;
		switch (choice) {
			//valid input
		case 1: case 2: case 3: case 4: case 5:
			SubMenu(choice);
			choice = 0; //Return user to Main Menu
			break;
			//Exit
		case 6:
			"Goodbye...";
			break;
			//invalid input
		default:
			choice = -1; //prompt user to re-enter Option
			cin.clear(); //clear the buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the next line of input - to fix cin bug
			break;
		}
	} while (choice == -1 || choice == 0);
}
int SubMenu(int choice) {
	system("cls");//clear screen
	switch (choice) {
	case 1:
		cout
			<< "*************************\n"
			<< "*     Create Player     *\n"
			<< "*************************\n";
		break;
	case 2:
		cout
			<< "*************************\n"
			<< "*      Edit Player      *\n"
			<< "*************************\n";
		break;
	case 3:
		cout
			<< "*************************\n"
			<< "*     Delete Player     *\n"
			<< "*************************\n";
		break;
	case 4:
		cout
			<< "*************************\n"
			<< "*      Print Player     *\n"
			<< "*************************\n";
		break;
	case 5:
		cout
			<< "*************************\n"
			<< "*       Print Team      *\n"
			<< "*************************\n";
		break;
	}
	system("pause");
	return choice;
}
void PopulateTestData() {
	createPlayer("Dan", "Masci", "01/01/95");
	createPlayer("Alex", "Friesen", "01/01/95");
	createPlayer("Alex", "Andriishyn", "01/01/95");
	createPlayer("Mike", "Masci", "01/01/95");
	createPlayer("Joel", "Masci", "01/01/95");
	createPlayer("Jesse", "Masci", "01/01/95");
	createPlayer("Judy", "Masci", "01/01/95");
	createPlayer("John", "Masci", "01/01/95");
	createPlayer("Sarah", "Masci", "01/01/95");
	createPlayer("Anna", "Masci", "01/01/95");
}
void createPlayer(string firstName, string lastName, string dob) {
	//Create Dummy-Player for PopulateTestData() by inputting Players into db
	cout << "createPlayer()\n";
}


