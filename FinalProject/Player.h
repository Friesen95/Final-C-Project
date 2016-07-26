#pragma once
#include <string>

class Player
{
public:
	Player();
	Player(std::string, std::string, std::string);
	std::string firstName;
	std::string lastName;
	std::string dateOfBirth;

	std::string getFirstName();
	std::string getLastName();
	std::string getDateOfBirth();

	void setFirstName(std::string);
	void setLastName(std::string);
	void setDateOfBirth(std::string);
	~Player();
};

