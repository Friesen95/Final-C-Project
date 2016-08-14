#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();
	Player(string, string, string);

	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	string getDateOfBirth() const;

	void setId(int id);
	void setFirstName(string);
	void setLastName(string);
	void setDateOfBirth(string);
private:
	int id;
	string firstName;
	string lastName;
	string dateOfBirth;
};

