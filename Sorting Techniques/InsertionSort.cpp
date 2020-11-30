#include <iostream>
using namespace std;

class Array
{
private:
	int *array, size;

public:
	Array(int);
	void init();
	void insertionSort();
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

void Array::insertionSort()
{
	/**
	 * let n = number of elements
	 * Time Complexity :
	 * 					min= O(n)
	 * 					max=O(n^2)
	 * this algorithm is adaptive in nature
	 * This is stable algorithm
	 * number of Swap=number of Comparisons = n(n-1)/2 = O(n^2)
	 * */
	for (int i = 0; i < size; i++)
	{
		int j=i-1;
		int x=array[i];
		while (j>-1 && array[j]>x)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=x;
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
	a.insertionSort();
	a.display();
	return 0;
}
