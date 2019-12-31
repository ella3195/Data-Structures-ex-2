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
		data = NULL;
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

void minHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left] > data[node]))
	{
		max = left;
	}
	else max = node;
	if ((right < heapSize) && (data[right] > data[max]))
	{
		max = right;
	}
	if (max != node)
	{
		Swap(data[node], data[max]);
		FixHeap(max);
	}
}

Person* minHeap::Max() // ??
{
}

Person* minHeap::DeleteMax()
{
	if (heapSize < 1)
	{
		return 0; //error
	}
	else
	{
		Person* max = data[0];
		heapSize--;
		data[0] = data[heapSize];
		FixHeap(0);
		return(max);
	}
}

int minHeap::Insert(Person* person)
{
	if (heapSize == maxSize)
	{
		return 0;//error
	}
	int i = heapSize;
	heapSize++;
	while ((i > 0) && data[Parent(i)] < person)
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = person;
}

minHeap::minHeap(Person *arr[], int n) //should be FLOYD
{
	heapSize = maxSize = n;

	data = arr;
	allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}


void minHeap::MakeEmpty()
{

}

bool minHeap::IsEmpty()
{

}

void minHeap::Swap(Person* a, Person *b)
{

}



