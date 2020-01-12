#include "ui.h"

Ui::Ui(System *system)
{
	this->system = system;
}

Ui::Ui(const Ui& other)
{
	this->system = other.system;
}

Ui::~Ui()
{
}

int Ui::getIDFromUser(){
	int input;
	cin >> input;
	if (input <= 0) //invalid id
	{
		cout << "The id is invalid." << endl;
		return 0;
	}
	return input;
}


int Ui::getUserSelection()
{
	int input;
	cin >> input;
	if (input >= 1 && input <= system->getTotalPeople())
	{
		return input;
	}
	cout << "selection is invalid." << endl;
	return 0;
}


const char* Ui::getNameFromUser()
{
	char userInput[MAX_NAME_LEN];
	cin.getline(userInput, MAX_NAME_LEN);
	return userInput;
}

