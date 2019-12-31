#include "system.h"

int System::getTotalPeople()
{
	return totalPeople;
}

void System::addPerson(Person* newPerson)
{
	allPeople[totalPeople] = newPerson;
}

System::System(int numOfPeople)
{
	totalPeople = 0;
	allPeople = new Person*[numOfPeople];
}

Person** System::getAllPeople()
{
	return allPeople;
}

System::~System()
{
	for (int i = 0; i < totalPeople; i++)
	{
		delete allPeople[i];
	}
	delete[] allPeople;

}

Person* System::getPersonByID(int id)
{
	for (int i =0; i < totalPeople; i++)
	{
		if (allPeople[i]->getID() == id)
		{
			return allPeople[i];
		}
		else
		{
			return 0;
		}
	}
}