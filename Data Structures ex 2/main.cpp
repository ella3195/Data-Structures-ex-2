#include <iostream>
#include "ui.h"
#include "person.h"
#include "bsTree.h"
#include <stdlib.h>
#include <time.h> 
using namespace std;

const Person& RandSelection(Person **people, int size, int k, int& NumComp);
int Partition(Person **arr, int size, int& numComp);

int main()
{
	int num;
	int id;
	int numComp;
	int selection;
	char name[20];
	//
	//cout << "Please enter the number of Persons to create: " << endl;  //just for us, we will check the tests on mama
	//cin >> num;

	System system(5);
	Ui ui(&system);
	Person Tom("Tom", 204785034);
	Person Adi("Adi", 317586955);
	Person Yosi("Yosi", 308584867);
	Person Dikla("Dikla", 284985069);
	Person Niv("Niv", 205674857);

	system.addPerson(&Tom);
	system.addPerson(&Adi);
	system.addPerson(&Yosi);
	system.addPerson(&Dikla);
	system.addPerson(&Niv);
	int NumComp = 0;
	Person** allPeople = system.getAllPeople();
	Person k = RandSelection(allPeople, 5, 5, NumComp);
	k.show();
	cin >> num;

	//for (int i = 0; i < num; i++)// create all persons
	//{
	//	 id = ui.getIDFromUser();
	//	 if (id && !system.getPersonByID) //return 0 if there's no person with this id
	//	 {
	//		 name = ui.getNameFromUser();
	//	 }
	//	 else
	//	 {
	//		 cout << "Exiting." << endl;
	//		 exit(1);
	//	 }
	//	 Person* newPerson = new Person(name, id);
	//	 system.addPerson(newPerson);
	//}


	//selection = ui.getUserSelection();
	//if (!selection)
	//{
	//	cout << "Exiting." << endl;
	//	exit(1);
	//}
	//else
	//{
	//	Person person = RandSelection(system.getAllPeople(), selection, numComp);
	//	person.show();
	//	cout << "RandSelection: " << numComp << endl;
	//	person = selectHeap(system.getAllPeople(), selection, numComp);
	//	cout << "selectHeap: " << numComp << endl;
	//	person = BST(system.getAllPeople(), selection, numComp);
	//	cout << "BST: " << numComp << endl;
	//}
}


const Person& RandSelection(Person **people, int size, int k, int& NumComp)
{
	int pivot = Partition(people, size, NumComp);
	if (pivot == k - 1)
		return *people[pivot];
	if (pivot > k - 1)
		return RandSelection(people, pivot + 1, k, NumComp);
	else
		return RandSelection(people + pivot + 1, size - pivot - 1, k, NumComp);
}

int Partition(Person **arr, int size, int& numComp)
{//algo is wrong. need to follow pivot
	srand(time(nullptr));
	//int pivot = rand() % size;
	int pivot = 0;
	int left = 0, right = size - 1;
	Person temp = *arr[0];
	*arr[0] = *arr[pivot];
	*arr[pivot] = temp;
	while (left < right)
	{
		if (arr[left]->getID() > arr[right]->getID())
		{
			temp = *arr[left];
			*arr[left] = *arr[right];
			*arr[right] = temp;
			left++;
		}
		else
		{
			right--;
		}
		numComp++;
	}
	temp.setName(nullptr);
	return left;
}

//const Person & RandSelection(Person*[], int k, int &NumComp)
//{
//
//}
//
//const Person & selectHeap(Person*[], int k, int &NumComp)
//{
//
//}
//
//const Person & BST(Person*[], int k, int &NumComp)
//{
//
//}
