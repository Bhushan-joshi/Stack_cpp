#include <iostream>
using namespace std;

class Node
{
public:
	Node *prev;
	int data;
	Node *next;
};

class DoublyLL
{
private:
	Node *head;
	Node *last;

public:
	DoublyLL();
	void append(int);
	void insert(int, int);
	int deleteNode(int);
	void display();
	// ~DoublyLL();
};
DoublyLL::DoublyLL()
{
	head = nullptr;
	last = nullptr;
}

void DoublyLL::append(int x)
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
		last->next = t;
		last = last->next;
	}
}

void DoublyLL::display()
{
	Node *p = head;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

void DoublyLL::insert(int pos, int x)
{
	Node *t = new Node;
	if (pos == 1)
	{
		t->data = x;
		t->prev = nullptr;
		t->next = head;
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

int DoublyLL::deleteNode(int pos)
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