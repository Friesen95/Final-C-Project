#include "Player.h"

using namespace std;

Player::Player() {}
Player::Player(string firstName, string lastName, string dateOfBirth)
	: firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth)
{

}

Player::~Player()
{
}

string Player::getFirstName() {
	return firstName;
}

string Player::getLastName() {
	return lastName;
}

string Player::getDateOfBirth() {
	return dateOfBirth;
}

void Player::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Player::setLastName(string lastName) {
	this->lastName = lastName;
}

void Player::setDateOfBirth(string dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}
