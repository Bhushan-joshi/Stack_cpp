#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class CircularLikedList
{
private:
	Node *head;
	Node *last;
	int length = 0;

public:
	CircularLikedList()
	{
		head = nullptr;
		last = nullptr;
	}
	void append(int);
	void insert(int, int);
	int deleteNode(int);
	void display();
	~CircularLikedList();
};

void CircularLikedList::append(int x)
{
	Node *t = new Node;
	t->data = x;
	t->next = nullptr;
	if (head == nullptr)
	{
		head = last = t;
	}
	else
	{
		last->next = t;
		last = t;
		last->next = head;
	}
	length++;
}

void CircularLikedList::display()
{
	Node *p = head;
	do
	{
		cout << p->data << endl;
		p = p->next;
	} while (p != head);
}

void CircularLikedList::insert(int pos, int x)
{
	if (pos <= length)
	{
		Node *p = head;
		Node *t = new Node;
		if (pos == 1)
		{
			t->data = x;
			t->next = head;
			while (p->next != head)
			{
				p = p->next;
			}
			p->next = t;
			head = t;
			length++;
		}
		else
		{
			for (int i = 0; i < pos - 1; i++)
			{
				p = p->next;
			}
			t->data = x;
			t->next = p->next;
			p->next = t;
			length++;
		}
	}
	else
	{
		cout << "Please Enter a valid index" << endl;
	}
}

int CircularLikedList::deleteNode(int pos)
{
	int x = -1;
	if (pos <= length)
	{
		Node *t = new Node;
		Node *p = head;
		if (pos == 1)
		{
			while (p->next != head)
			{
				p = p->next;
			}
			p->next = head->next;
			x = head->data;
			delete head;
			head = p->next;
		}
		else
		{
			Node *q;
			for (int i = 0; i < pos - 2; i++)
			{
				p = p->next;
			}
			q = p->next;
			if (q->next != nullptr)
			{
				p->next = q->next;
				x = q->data;
				delete q;
			}
		}

		return x;
	}
	else
	{
		return -1;
	}
}

CircularLikedList::~CircularLikedList(){
	Node *p = head;
	do
	{
		p = p->next;
		delete head;
		head=p;
	} while (p != head);
	cout<<"Memory released Successfully!"<<endl;
}