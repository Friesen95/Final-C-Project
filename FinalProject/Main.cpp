/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include "Header.h"
#include "Player.h"
#include "Storage.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Storage db = Storage();
Player player = Player();

int main()
{
	PopulateTestData();
	MainMenu();

	system("PAUSE");
	return 0;
}
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
			cin.clear(); //clear the buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the next line of input - to fix cin bug
			SubMenu(choice);
			choice = 0; //Return user to Main Menu
			player.clear(); //Clear Player data
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
void SubMenu(int choice) {
	int playerId = -1;
	string firstName, lastName, dob;
	system("cls");//clear screen
	switch (choice) {
	case 1:
		cout
			<< "*************************\n"
			<< "*     Create Player     *\n"
			<< "*************************\n";
		db.printAllPlayers();
		//Create First Name
		cout << "First Name: ";
		getline(cin, firstName);
		if (firstName != "")
			player.setFirstName(firstName);
		//Create Last Name
		cout << "Last Name: ";
		getline(cin, lastName);
		if (lastName != "")
			player.setLastName(lastName);
		cout << "DOB (mm/dd/yyyy): ";
		getline(cin, dob);
		if (dob != "")
			player.setDateOfBirth(dob);

		db.createPlayer(player); //Create player
		break;
	case 2:
		cout
			<< "*************************\n"
			<< "*      Edit Player      *\n"
			<< "*************************\n";
		db.printAllPlayers();
		//Choose Player by Id
		cout << "Which player would you like to edit?" << endl
			<< "Player #";
		cin >> playerId;
		player.setId(playerId);
		db.getPlayer(player); //print selected player
		cout << "Leave any fields blank that you don't want changed..." << endl;
		cin.clear(); //clear the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the next line of input - to fix cin bug
		//Edit First Name
		cout << "First Name (" << player.getFirstName() << "): ";
		getline(cin, firstName);
		if (firstName != "")
			player.setFirstName(firstName);
		//Edit Last Name
		cout << "Last Name (" << player.getLastName() << "): ";
		getline(cin, lastName);
		if (lastName != "")
			player.setLastName(lastName);
		//Edit Date of Birth
		cout << "DOB (" << player.getDateOfBirth() << "): ";
		getline(cin, dob);
		if (dob != "")
			player.setDateOfBirth(dob);

		db.updatePlayer(player); //update player
		db.getPlayer(player); //print updated info
		break;
	case 3:
		cout
			<< "*************************\n"
			<< "*     Delete Player     *\n"
			<< "*************************\n";
		db.printAllPlayers();
		cout << "Which player would you like to delete?" << endl
			<< "Player #";
		cin >> playerId;
		player.setId(playerId);
		db.deletePlayer(player);
		break;
	case 4:
		cout
			<< "*************************\n"
			<< "*      Print Player     *\n"
			<< "*************************\n";
		player.setId(1);
		player.setFirstName("Dan");
		player.setLastName("Masci");
		db.getPlayer(player);
		break;
	case 5:
		cout
			<< "*************************\n"
			<< "*       Print Team      *\n"
			<< "*************************\n";
		db.printAllPlayers();
		break;
	}
	system("pause");
}
void PopulateTestData() {
	player.clear(); //Clear Player data
	db.seedDb();
}


