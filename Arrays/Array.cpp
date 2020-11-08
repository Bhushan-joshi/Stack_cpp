#include <iostream>
using namespace std;

class Array
{
private:
	int size, length;
	int *array;

public:
	Array(int);
	void init(int);
	void display();
	void append(int);
	void insert(int, int);
	void delete_num(int);
	int simple_linear_search(int);
	int advanced_linear_search(int);
	int binary_search(int);
	void reverse();
	void selection_sort();
	~Array();
};

Array::Array(int sz)
{
	array = new int[sz];
	size = sz;
	length = 0;
	for (int i = 0; i < sz; i++)
	{
		array[i] = 0;
	}
}
Array::~Array()
{
	delete[] array;
	array = nullptr;
}
void Array::init(int l)
{
	int x;
	for (int i = 0; i < l; i++)
	{
		cin >> x;
		array[i] = x;
		length++;
	}
}
void Array::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}
void Array::append(int n)
{
	array[length-1] = n;
	length++;
}
void Array::insert(int index, int num)
{
	if (index > 0 && index < length)
	{
		for (int i = length; i > index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = num;
		length++;
	}
}
void Array::delete_num(int index)
{
	if (index > 0)
	{
		for (int i = index; i < length - 1; i++)
		{
			array[i] = array[i + 1];
		}
		array[length] = 0;
		length--;
	}
}
int Array::simple_linear_search(int key)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int Array::advanced_linear_search(int key)
{
	/**
	 * This search is for repeatedly search element 
	 * this search bring the element froword so next time it will take less time
	 * */
	for (int i = 0; i < length; i++)
	{
		if (array[i] == key)
		{
			swap(array[i], array[i - 1]);
			return i - 1;
		}
	}
	return -1;
}
int Array::binary_search(int key)
{
	int l, mid, h;
	l = 0;
	h = length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == array[mid])
			return mid;
		else if (key < array[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

void Array::reverse()
{
	int temp[length];
	for (int i = 0, j = length - 1; j >= 0; i++, j--)
	{
		temp[i] = array[j];
	}
	for (int i = 0; i < length; i++)
	{
		array[i] = temp[i];
	}
}
