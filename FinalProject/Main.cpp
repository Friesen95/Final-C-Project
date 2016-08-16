#include "Header.h"
#include "Player.h"
#include "Storage.h"
#include "Validator.h"
#include <stdlib.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace Validator;

Storage db = Storage();
Player player = Player();

int main()
{
	PopulateTestData();
	MainMenu();
	
	system("PAUSE");
	return 0;
}

void MainMenu() 
{
	int choice = -1;
	string message;
	do {
		system("cls");//clear screen
		cout
			<< "*************************\n"
			<< "*       Main Menu       *\n"
			<< "*************************\n"
			<< "1) Create Player\n"
			<< "2) Edit Player\n"
			<< "3) Delete Player\n"
			<< "4) Print Player\n"
			<< "5) Print Team\n"
			<< "0) Exit\n"
			<< message;
		// Get answer from User
		choice = validateAnswer(5);
		switch (choice) {
		case 1: case 2: case 3: case 4: case 5:
			SubMenu(choice);
			choice = -1; //Return user to Main Menu
			player.clear(); //Clear Player data
			break;
			//Exit
		case 0:
			cout << "Goodbye. ";
			break;
		}
	} while (choice != 0);
}

void SubMenu(int choice) 
{
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

void PopulateTestData() 
{
	player.clear(); //Clear Player data
	db.seedDb();
}


