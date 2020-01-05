#include <iostream>
#include "ui.h"
#include "person.h"
#include "bsTree.h"
using namespace std;

int main()
{
	int num;
	int id;
	int numComp;
	int selection;
	const char *name;
	//
	//cout << "Please enter the number of Persons to create: " << endl;  //just for us, we will check the tests on mama
	//cin >> num;

	/*System system(num);
	Ui ui(&system);*/

	BSTree tree;
	tree.Insert(8, "eight");
	tree.Insert(10, "ten");
	tree.Insert(2, "two");
	tree.Insert(9, "nine");
	tree.Insert(23, "twentythree");
	tree.Insert(18, "eighteen");
	tree.Insert(12, "twelve");
	tree.Insert(14, "fourteen");
	tree.Insert(16, "sixteen");
	tree.Insert(17, "seventeen");
	tree.Insert(5, "five");
	tree.getRoot()->InOrder();
	while (1) {
		cin >> num;
		tree.Delete(num);
		tree.getRoot()->InOrder();
	}


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
