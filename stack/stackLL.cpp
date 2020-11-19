#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
private:
	Node *top;

public:
	Stack();
	void push(int);
	int pop();
	void display();
	int peek(int);
	~Stack();
};
Stack::Stack()
{
	top = nullptr;
}

void Stack::push(int x)
{
	Node *t = new Node;
	if (t == nullptr) //heap is full
	{
		cout << "Stack overflow!\n";
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int Stack::pop()
{
	int x = -1;
	if (top == nullptr)
	{
		cout << "Stack is Empty\n";
	}
	else
	{
		Node *p;
		p = top;
		top = top->next;
		x = p->data;
		delete p;
	}
	return x;
}

int Stack::peek(int pos){
	int x=-1;
	Node *p=top;
	for (int i = 0; i < pos-1&&p!=nullptr; i++)
	{
		p=p->next;	
	}
	if (p!=nullptr)
	{
		x=p->data;
	}
	return x;
}

void Stack::display(){
	Node *p=top;
	while (p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

Stack::~Stack(){
	Node *p=top;
	while (p)
	{
		top=top->next;
		delete p;
		p=top;
	}
}