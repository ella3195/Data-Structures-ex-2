#ifndef __UI_H
#define __UI_H

#include <iostream>
#include "person.h"
#include "system.h"

using namespace std;

class Ui
{
private:
	System *system;

public:

	static constexpr int MAX_NAME_LEN = 21;

	Ui(System *system);
	Ui(const Ui& other);
	~Ui();


	const char* getNameFromUser();
	int getIDFromUser();
	int getUserSelection();

};



#endif // !__UI_H
