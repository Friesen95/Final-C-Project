#include "Header.h"
#include "Player.h"
#include "Storage.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Storage storage;
	Player p;

	// Can add a player
	storage.createPlayer(p);

	// Can print all players
	storage.printAllPlayers();

	// Can retrieve a player
	p.setId(1);
	p.setFirstName("Alex");
	p.setLastName("Andriishyn");
	storage.getPlayer(p);

	// Can update a player
	p.setFirstName("Alexander");
	storage.updatePlayer(p);

	// Can delete a player
	storage.deletePlayer(p);

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
	//Create Dummy-Player for PopulateTestData() by inputting Players into players.dat
}


