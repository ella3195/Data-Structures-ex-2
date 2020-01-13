#include <iostream>
#include "ui.h"
#include "person.h"
#include "bsTree.h"
#include "minHeap.h"
#include <stdlib.h>
#include <time.h> 
using namespace std;

const Person& RandSelection(Person **people, int size, int k, int& NumComp);
const Person & selectHeap(Person *arr[], int size, int k, int &NumComp);
const Person & BST(Person*[], int size, int k, int &NumComp);
int Partition(Person *arr[], int size, int& numComp);

int main()
{
	int num;
	int id;
	int numComp = 0;
	int selection;
	char *name;
	Person** people, **pepcpy;

	srand(time(nullptr));

	cout << "Please enter the number of Persons to create: " << endl;  //just for us, we will check the tests on mama
	cin >> num;
	people = new Person * [num];
	pepcpy = new Person * [num];
	System system(5);
	Ui ui(&system);

		for (int i = 0; i < num; i++)// create all persons
		{
			id = ui.getIDFromUser();
			if (id && !system.getPersonByID(id)) //return 0 if there's no person with this id
			{
				ui.getNameFromUser(name);
			}
			else
			{
				cout << "Exiting." << endl;
				exit(1);
			}
			Person* newPerson = new Person(name, id);
			system.addPerson(newPerson);
		}
		people = system.getAllPeople();

		//Copy content of people arr
		for (int i = 0; i < num; i++)
			pepcpy[i] = new Person(*people[i]);

		selection = ui.getUserSelection();
		if (!selection)
		{
			cout << "Exiting." << endl;
			exit(1);
		}
		else
		{
			int size = system.getTotalPeople();
			Person person = RandSelection(pepcpy, size, selection, numComp);
			person.show();
			cout << "RandSelection: " << numComp << "comparisons" << endl;
			numComp = 0;

			for (int i = 0; i < num; i++)
				pepcpy[i] = new Person(*people[i]);
			person = selectHeap(pepcpy, size, selection, numComp);
			person.show();
			cout << "selectHeap: " << numComp << "comparisons" << endl;
			numComp = 0;

			for (int i = 0; i < num; i++)
				pepcpy[i] = new Person(*people[i]);
			person = BST(pepcpy, size, selection, numComp);
			person.show();
			cout << "BST: " << numComp << "comparisons" << endl;
		}

	cin >> num;
}

/*
Complexity of RandSelection:
Tworst(n) = n^2
Taverage(n) = n
*/
const Person& RandSelection(Person **people, int size, int k, int& NumComp) // k = 80
{
	if (size == 1)
	{
		return *people[0];
	}
	else
	{
		int pivot = Partition(people, size, NumComp);
		if (pivot == k - 1)
			return *people[pivot];
		if (pivot > k - 1)
			return RandSelection(people, pivot, k, NumComp);
		else
			return RandSelection(people + pivot + 1, size - pivot - 1, k - pivot - 1, NumComp);
	}
}

int Partition(Person *arr[], int size, int& numComp) //check if works
{
	int pivot = rand() % size;
	int comp = size - 1;
	
	//placing pivot at beggining of arr:
	Person* temp = arr[0];
	arr[0] = arr[pivot];
	arr[pivot] = temp;
	pivot = 0;

	while (pivot != comp)
	{
		if (pivot < comp)
		{
			numComp++; //comparing keys
			if (arr[pivot]->getID() > arr[comp]->getID())
			{
				//switch:
				temp = arr[pivot];
				arr[pivot] = arr[comp];
				arr[comp] = temp;
				//keep track of pivot:
				int tmpIndex = comp;
				comp = pivot + 1;
				pivot = tmpIndex;
			}
			else
				comp--;
		}
		else
		{
			numComp++; //comparing keys
			if (arr[pivot]->getID() < arr[comp]->getID())
			{
				//switch:
				temp = arr[pivot];
				arr[pivot] = arr[comp];
				arr[comp] = temp;
				//keep track of pivot:
				int tmpIndex = comp;
				comp = pivot - 1;
				pivot = tmpIndex;
			}
			else
				comp++;
		}
	}
	return pivot;
}

/*
Complexity of selectHeap:
Tworst(n) = n*log(n) (if k==n)
Taverage(n) n*log(n) (k has equal probability of {0,..,n}, therefore averagely k==n/2)
*/
const Person & selectHeap(Person *arr[], int size, int k, int &NumComp)
{
	minHeap heap(arr, size, NumComp); //n
	for (int i = 0; i < k - 1; i++)
		heap.DeleteMin(NumComp);//log n
	return *heap.DeleteMin(NumComp);
}

/*
Complexity of BST:
Tworst(n) = n^2 (in case of sorted input)
Taverage(n) = n*log(n)
*/
const Person & BST(Person *arr[], int size, int k, int &NumComp)
{
	BSTree tree;
	//nlogn / n^2
	for (int i = 0; i < size; i++)
	{
		tree.Insert(arr[i]->getID(), arr[i]->getName(), NumComp);
	}
	//n / logn + k
	return *tree.FindKthPerson(k, NumComp);
}
