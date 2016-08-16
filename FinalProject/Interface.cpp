#include "Interface.h"
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
int playerId = -1;

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
			<< "4) Search Player\n"
			<< "5) Print Team\n"
			<< "0) Exit\n"
			<< message;
		// Get answer from User
		choice = validateAnswer(5);
		switch (choice) {
		case 1: case 2: case 3: case 4: case 5:
			player.clear(); //Clear Player data
			SubMenu(choice); //Go to Menu choice
			choice = -1; //Return user to Main Menu
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
	system("cls");//clear screen
	switch (choice) {
	case 1:
		cout
			<< "*************************\n"
			<< "*     Create Player     *\n"
			<< "*************************\n";
		db.printAllPlayers(); //Show all current players - before
		setPlayerFields(); //Get User Input for all fields
		db.createPlayer(player); //Create player

		system("cls");//clear screen
		cout
			<< "*********************************\n"
			<< "* " << player.getFirstName() << " " 
					<< player.getLastName() 
					<< " has been Created\n"
			<< "*********************************\n";
		db.printAllPlayers(); //Show all current players - after
		break;
	case 2:
		cout
			<< "*************************\n"
			<< "*      Edit Player      *\n"
			<< "*************************\n";
		db.printAllPlayers(); //Show all current players - before
		getPlayerIdFromUser("edit"); //Prompt user to choose an existing Player

		cout << endl << "Leave any fields blank that you don't want changed..." << endl;
		setPlayerFields(); //Get User Input for all fields
		db.updatePlayer(player); //update player

		system("cls");//clear screen
		cout
			<< "*********************************\n"
			<< "* Player #" << playerId << " has been Updated\n"
			<< "*********************************\n";
		db.printAllPlayers(); //Show all current players - after
		break;
	case 3:
		cout
			<< "*************************\n"
			<< "*     Delete Player     *\n"
			<< "*************************\n";
		db.printAllPlayers(); //Show all current players - before
		getPlayerIdFromUser("delete"); //Prompt user to choose an existing Player
		db.deletePlayer(player); //Delete player

		system("cls");//clear screen
		cout
			<< "*********************************\n"
			<< "* Player #" << playerId << " has been Deleted\n"
			<< "*********************************\n";
		db.printAllPlayers(); //Show all current players - after
		break;
	case 4:
		cout
			<< "*************************\n"
			<< "*      Search Player     *\n"
			<< "*************************\n";
		cout << "Leave any fields blank that you don't want to be searched by..." << endl;
		setPlayerFields(); //Get User Input for all fields
		db.getPlayers(player); //Return player if found
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

void getPlayerIdFromUser(string cmd) {
	do {
		cout << "Which player would you like to " << cmd << "?" << endl;
		cout << "Player #";
		cin >> playerId;
		player.setId(playerId);

		//fix buffer in case string is entered
		cin.clear(); //clear the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the next line of input - to fix cin bug
	} while (!db.setPlayer(player));
}

void setPlayerFields()
{
	string firstName, lastName, dob;

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
}

void PopulateTestData()
{
	player.clear(); //Clear Player data
	db.seedDb();
}