#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();
	Player(string, string, string);
	string firstName;
	string lastName;
	string dateOfBirth;

	string getFirstName();
	string getLastName();
	string getDateOfBirth();

	void setFirstName(string);
	void setLastName(string);
	void setDateOfBirth(string);
	~Player();
};

