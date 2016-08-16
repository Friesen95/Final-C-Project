#include "Validator.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int Validator::validateAnswer(int range)
{
	int answer = -1;
	string userInput = "";
	string errMsg = "Invalid input, please enter ";

	errMsg += "1 - " + to_string(range) + " or 0 to Exit: ";

	cout << "Option: ";
	while (getline(cin, userInput))
	{
		stringstream strStream(userInput);
		if (!(strStream >> answer))
		{
			// Parse error
			cout << errMsg;
			continue;
		}

		if ((answer > range) || (answer < 0))
		{
			cout << errMsg;
			continue;
		}
		char badChar;
		if (strStream >> badChar)
		{
			// If there was something after the number, e.g 2a
			cout << errMsg;
			continue;
		}

		// Input validated, quit the loop
		break;
	}

	return answer;
}