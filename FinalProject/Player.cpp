#include "Player.h"

using namespace std;

// add team name, number, salary and position 
Player::Player() {}
Player::Player(string firstName, string lastName, string dateOfBirth)
	: firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth)
{
	id = -1;
}

int Player::getId() const
{
	return id;
}

string Player::getFirstName() const
{
	return firstName;
}

string Player::getLastName() const
{
	return lastName;
}

string Player::getDateOfBirth() const
{
	return dateOfBirth;
}

void Player::setId(int id)
{
	this->id = id;
}

void Player::setFirstName(string firstName) 
{
	this->firstName = firstName;
}

void Player::setLastName(string lastName) 
{
	this->lastName = lastName;
}

void Player::setDateOfBirth(string dateOfBirth) 
{
	this->dateOfBirth = dateOfBirth;
}
void Player::clear() {
	id = -1;
	firstName = "";
	lastName = "";
	dateOfBirth = "";
}