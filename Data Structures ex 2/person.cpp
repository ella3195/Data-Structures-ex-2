#include "person.h"


Person::Person(const char* name, int id)
{
	setName(name);
	setID(id);
}

Person::Person(const Person& other)
{
	setName(other.name);
	setID(other.id);
}

Person::~Person()
{
	delete[] name;
}

int Person::getID() const
{
	return id;
}

const char* Person::getName() const
{
	return name;
}

void Person::setID(int id)
{
	this->id = id;
}

void Person::setName(const char *name)
{
	delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}


void Person::show() const
{
	cout << id << " " << name;
}
