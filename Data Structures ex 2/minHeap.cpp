#include "minHeap.h"


minHeap::minHeap(int max)
{
	data = new Person*[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

minHeap::~minHeap()
{
	if (allocated)
	{
		delete[] data;
		data = nullptr;
	}
}

int minHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int minHeap::Left(int node)
{
	return (2 * node + 1);
}

int minHeap::Right(int node)
{
	return (2 * node + 2);
}


//worst = log n
//average = log n
void minHeap::FixHeap(int node, int &numComp)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	if (left < heapSize)//is there a left son
	{
		numComp++;//comparing keys
		if (data[left]->getID() > data[node]->getID())
		{
			max = left;
		}
	}
	else max = node;

	if (right < heapSize)//is there a right son
	{
		numComp++;//comparing keys
		if (data[right]->getID() > data[max]->getID())
		{
			max = right;
		}
	}
	if (max != node)
	{
		Swap(data[node], data[max]);
		FixHeap(max, numComp);
	}
}

Person* minHeap::Min()
{
	return data[0];
}


//worst = average = log n
Person* minHeap::DeleteMin(int &numComp)
{
	if (heapSize < 1)
	{
		return 0; //error
	}
	else
	{
		Person* min = data[0];
		heapSize--;
		data[0] = data[heapSize];
		FixHeap(0, numComp);
		return(min);
	}
}

//worst = average = log n
int minHeap::Insert(Person* person)
{
	if (heapSize == maxSize)
	{
		return 0;//error
	}
	int i = heapSize;
	heapSize++;
	while ((i > 0) && data[Parent(i)]->getID() < person->getID())//degrading parents who's key is smaller
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = person;
}

//n
minHeap::minHeap(Person *arr[], int n, int &numComp) //FLOYD
{
	heapSize = maxSize = n;

	data = arr;
	allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i, numComp);
	}
}


void minHeap::MakeEmpty()
{
	if (allocated)
	{
		delete[] data;
	}
	data = nullptr;
	maxSize = heapSize = 0;
}

bool minHeap::IsEmpty()
{
	return heapSize == 0;
}


void minHeap::Swap(Person*& a, Person*& b)
{
	Person *temp = a;
	a = b;
	b = temp;
}



