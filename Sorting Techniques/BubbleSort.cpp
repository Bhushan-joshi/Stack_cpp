#include <iostream>
using namespace std;

class Array
{
private:
	int *array, size;

public:
	Array(int);
	void init();
	void bubbleSort();
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

void Array::bubbleSort()
{
	/**
	 * let n = number of elements
	 * Time Complexity :
	 * 					min= O(n)
	 * 					max=O(n^2)
	 * by adding flag we made it adaptive
	 * This is stable algorithm
	 * number of Swap=number of Comparisons = n(n-1)/2 = O(n^2)
	 * */
	int flag;
	for (int i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
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

int main(int argc, char const *argv[])
{
	Array a(5);
	a.init();
	a.bubbleSort();
	a.display();
	return 0;
}
