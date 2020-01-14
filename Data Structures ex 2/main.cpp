#include <iostream>
#include "person.h"
#include "bsTree.h"
#include "minHeap.h"
#include <stdlib.h>
#include <time.h> 
using namespace std;

#pragma warning(disable:4996)

const Person& RandSelection(Person **people, int size, int k, int& NumComp);
const Person & selectHeap(Person *arr[], int size, int k, int &NumComp);
const Person & BST(Person*[], int size, int k, int &NumComp);
int Partition(Person *arr[], int size, int& numComp); 
bool isInArr(Person** arr, int size, int id);

int main()
{
	int num;
	int id;
	int numComp = 0;
	int selection;
	char name[21];

	Person** people1, ** people2, ** people3;

	srand(time(nullptr));

	cin >> num;

	people1 = new Person * [num];
	people2 = new Person * [num];
	people3 = new Person * [num];


		for (int i = 0; i < num; i++)// create all persons
		{
			cin >> id;
			if (id>0 && !isInArr(people1,i,id)) //return 0 if there's no person with this id
			{
				cin.ignore();
				cin.getline(name, 21);
			}
			else
			{
				cout << "Invalid input. Exiting." << endl;
				exit(1);
			}
			Person* newPerson = new Person(name, id);
			people1[i] = newPerson;
			people2[i] = new Person(*newPerson);
			people3[i] = new Person(*newPerson);
		}
		cin >> selection;
		if (selection<=0||selection>num)
		{
			cout << "Invalid input. Exiting." << endl;
			exit(1);
		}
		else
		{
			Person person = RandSelection(people1, num, selection, numComp);
			person.show();
			cout << "RandSelection: " << numComp << " comparisons" << endl;
			numComp = 0;

			person = selectHeap(people2, num, selection, numComp);
			cout << "selectHeap: " << numComp << " comparisons" << endl;
			numComp = 0;

			person = BST(people3, num, selection, numComp);
			cout << "BST: " << numComp << " comparisons" << endl;
		}
		for (int i = 0; i < num; i++)
		{
			delete people1[i];
			if (people2[i]->getID() > 0) //minheap deleted some of the people
				delete people2[i];
			delete people3[i];
		}
		delete[]people1;
		delete[]people2;
		delete[]people3;
}

bool isInArr(Person** arr, int size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getID() == id)
			return true;
	}
	return false;
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
