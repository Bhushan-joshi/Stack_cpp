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
	~Queue();
	void enQueue(int);
	int deQueue();
	void display();
};

Queue::Queue()
{
	size = 10;
	front = rear = 0;
	arr = new int[size];
}
Queue::Queue(int size)
{
	this->size = size;
	front = rear = 0;
	arr = new int[this->size];
}
void Queue::enQueue(int x)
{
	if ((rear + 1) % size == front)
	{
		cout << "Queue is full !" << endl;
	}
	else
	{
		rear = (rear + 1) % size;
		arr[rear] = x;
	}
}

int Queue::deQueue()
{
	int x = -1;
	if (rear == front)
	{
		cout << "Queue is Empty !\n";
	}
	else
	{
		front = (front + 1) % size;
		x = arr[front];
		arr[front] = NULL;
	}
}

void Queue::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}
Queue::~Queue()
{
	delete[] arr;
	display();
	cout<<"----------\n";
	cout<<*arr<<endl;
}