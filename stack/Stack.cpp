/**
 * Stack using array
 *  * */
#include <iostream>
using namespace std;

class Stack
{
public:
	int size;
	int top;
	int *arr;
};

class StackArray
{
private:
	Stack st;

public:
	StackArray(int);
	void push(int);
	int pop();
	void display();
	int peek(int);
	bool isEmpty();
	bool isFull();
};

StackArray::StackArray(int sz)
{
	st.size = sz;
	st.top = -1;
	st.arr = new int[st.size];
}
void StackArray::push(int x)
{
	if (st.top == st.size - 1)
	{
		cout << "Stack Overflow!" << endl;
	}
	else
	{
		st.top++;
		st.arr[st.top] = x;
	}
}

int StackArray::pop()
{
	int x = -1;
	if (st.top == -1)
	{
		cout << "Stack Underflow !" << endl;
	}
	else
	{
		x = st.arr[st.top];
		st.top--;
	}
	return x;
}
int StackArray::peek(int pos)
{
	int x = -1;
	if (st.top - pos + 1 < 0)
	{
		cout << "Invalid position";
	}
	else
	{
		x = st.arr[st.top - pos + 1];
	}
	return x;
}

bool StackArray::isEmpty()
{
	if (st.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool StackArray::isFull()
{
	if (st.top == st.size - 1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void StackArray::display()
{
	for (int i = st.top; i >= 0; i--)
	{
		cout << st.arr[i] << endl;
	}
}