#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "person.h"

class System
{
public:

	System(int numOfPeople);
	~System();
	void addPerson(Person *newPerson);
	int getTotalPeople();
	Person *getPersonByID(int id);
	Person **getAllPeople();

private:
	System(const System& other);

	int totalPeople;
	Person **allPeople;
};

#endif // !__SYSTEM_H
