#include <iostream>
using namespace std;

class Array
{
private:
	int *array, size;

public:
	Array(int);
	void init();
	void selectionSort();
	void display();
	~Array();
};

Array::Array(int sz)
{
	array = new int[sz];
	this->size = sz;
}
void Array::init()
{
	int temp;
	cout << "Enter Elements to insert in Array:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		array[i] = temp;
	}
}

void Array::selectionSort()
{
	/**
	 * let n = number of elements
	 * Time Complexity :
	 * 					max=O(n^2)
	 * not a Adaptive 
	 * not a Stable
	 * number of Swap=O(1)
	 * number of Comparisons = n(n-1)/2 = O(n^2)
	 * */
	int i, j, k;
	for (i = 0; i < size - 1; i++)
	{
		for (j = k = i; j < size; j++)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
			swap(array[i], array[k]);
		}
	}
}

void Array::display()
{
	cout << "Sorted list :\n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}

Array::~Array()
{
	delete[] array;
}