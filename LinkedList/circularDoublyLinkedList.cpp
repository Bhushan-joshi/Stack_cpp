#include <iostream>
using namespace std;

class Node
{
public:
	Node *prev;
	int data;
	Node *next;
};

class CircularDLL
{
private:
	Node *head;
	Node *last;

public:
	CircularDLL();
	void append(int);
	void insert(int, int);
	int deleteNode(int);
	void display();
	// ~CircularDLL();
};
CircularDLL::CircularDLL()
{
	head = nullptr;
	last = nullptr;
}

void CircularDLL::append(int x)
{
	Node *t = new Node;
	t->data = x;
	t->prev = nullptr;
	t->next = nullptr;
	if (head == nullptr)
	{
		head = last = t;
	}
	else
	{
		t->prev = last;
		last = t;
		last->next= head;
	}
}

void CircularDLL::display()
{
	Node *p = head;
	do
	{
		cout << p->data << endl;
		p = p->next;
	}while (p!=head);
}

void CircularDLL::insert(int pos, int x)
{
	Node *t = new Node;
	if (pos == 1)
	{
		t->data = x;
		t->prev = nullptr;
		t->next = head;
		last->next=t;
		head->prev = t;
		head = t;
	}
	else
	{
		t->data = x;
		Node *p = head;
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		t->prev = p;
		if (p->next)
		{
			p->next->prev = t;
		}
		p->next = t;
	}
}

int CircularDLL::deleteNode(int pos)
{
	Node *p;
	int x = -1;
	if (pos == 1)
	{
		p = head;
		head = head->next;
		x = p->data;
		delete p;
		if (head)
		{
			head->prev = nullptr;
		}
	}else
	{
		p=head;
		for (int i = 0; i < pos-1; i++)
		{
			p=p->next;
		}
		p->prev->next=p->next;
		p->next->prev=p->prev;
		x=p->data;
		delete p;
	}
	
	return x;
}