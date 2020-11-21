#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class QueueLL
{
private:
	Node *front, *rear;

public:
	QueueLL();
	~QueueLL();
	void enQueue(int);
	int deQueue();
	void display();
};

QueueLL::QueueLL()
{
	front = rear = nullptr;
}
void QueueLL::enQueue(int x)
{
	Node *t = new Node;
	if (t == nullptr)
	{
		cout << "Queue is full due to lack of Heap memory\n";
	}
	else
	{
		t->data = x;
		t->next = nullptr;
		if (front == nullptr)
		{
			rear = front = t;
		}
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int QueueLL::deQueue()
{
	int x = -1;
	Node *p;
	if (front == nullptr)
	{
		cout << "queue is empty!\n";
	}
	else
	{
		p = front;
		front = front->next;
		x = p->data;
		delete p;
	}
	return x;
}

void QueueLL::display(){
	Node *p=front;
	while (p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

QueueLL::~QueueLL(){
	Node *p=front;
	while (p)
	{
		front=front->next;
		delete p;
		p=front;
	}
}
