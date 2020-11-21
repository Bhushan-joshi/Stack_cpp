#include <iostream>
using namespace std;

class Queue
{
private:
	int size;
	int front;
	int rear;
	int *arr;

public:
	Queue();
	Queue(int);
	void enQueue(int);
	int deQueue();
	void display();
};

Queue::Queue()
{
	size = 10;
	front = rear = -1;
	arr = new int[size];
}
Queue::Queue(int size)
{
	this->size = size;
	front = rear = -1;
	arr = new int[this->size];
}

void Queue::enQueue(int x)
{
	if (rear == size - 1)
	{
		cout << "Queue is Full\n";
	}
	else
	{
		rear++;
		arr[rear] = x;
	}
}

int Queue::deQueue()
{
	int x = -1;
	if (rear == front)
	{
		cout << "Queue is Empty!\n";
	}
	else
	{
		front++;
		x = arr[front];
		arr[front]=NULL;
	}
	return x;
}

void Queue::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}