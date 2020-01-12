#include "system.h"
#include <stdlib.h>
#include <time.h> 


int System::getTotalPeople()
{
	return totalPeople;
}

void System::addPerson(Person* newPerson)
{
	allPeople[totalPeople] = newPerson;
	totalPeople++;
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