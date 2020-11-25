#include <iostream>
using namespace std;

class Node
{
public:
	Node *Lchild;
	int data;
	Node *Rchild;
};

class BinaryTree
{
public:
	Node *Root;
	BinaryTree();
	~BinaryTree();
	void insert(int key);
	void inOrder(Node *);
	int Search(int);
	int height(Node *);
	Node *inPre(Node *);
	Node *inSucc(Node *);
	Node *Delete(Node *, int);
};

BinaryTree::BinaryTree()
{
	Root == nullptr;
}

void BinaryTree::insert(int key)
{
	Node *r = nullptr, *p;
	Node *t = Root;
	if (Root == nullptr)
	{
		p = new Node;
		p->data = key;
		p->Lchild = p->Rchild = nullptr;
		Root = p;
		return;
	}

	while (t != nullptr)
	{
		r = t;
		if (key == t->data)
		{
			return;
		}
		else if (key < t->data)
		{
			t = t->Lchild;
		}
		else
		{
			t = t->Rchild;
		}
	}
	p = new Node;
	p->data = key;
	p->Lchild = p->Rchild = nullptr;
	if (p->data < r->data)
	{
		r->Lchild = p;
	}
	else
	{
		r->Rchild = p;
	}
}
//send Root at p;
void BinaryTree::inOrder(Node *p)
{
	if (p)
	{
		inOrder(p->Lchild);
		cout << p->data << endl;
		inOrder(p->Rchild);
	}
}

int BinaryTree::Search(int key)
{
	Node *t = Root;
	while (t != nullptr)
	{
		if (key == t->data)
		{
			return t->data;
		}
		else if (key < t->data)
		{
			t = t->Lchild;
		}
		else
		{
			t = t->Rchild;
		}
	}
	return (-1);
}

int BinaryTree::height(Node *p)
{
	int x, y;
	if (p == NULL)
	{
		return 0;
	}
	x = height(p->Lchild);
	y = height(p->Rchild);
	return x > y ? x + 1 : y + 1;
}

Node *BinaryTree::inPre(Node *p)
{
	while (p && p->Rchild != nullptr)
	{
		p = p->Rchild;
	}
	return p;
}

Node *BinaryTree::inSucc(Node *p)
{
	while (p && p->Lchild != nullptr)
	{
		p = p->Lchild;
	}
	return p;
}
//Send Root at p
Node *BinaryTree::Delete(Node *p, int key)
{

	Node *q;
	if (p == NULL)
		return NULL;
	if (p->Lchild == nullptr && p->Rchild == nullptr)
	{
		if (p == Root)
			Root = nullptr;
		delete p;
		return NULL;
	}
	if (key < p->data)
	{
		p->Lchild = Delete(p->Lchild, key);
	}
	else if (key > p->data)
	{
		p->Rchild = Delete(p->Rchild, key);
	}
	else
	{
		if (height(p->Lchild) > height(p->Rchild))
		{
			q = inPre(p->Lchild);
			p->data = q->data;
			p->Lchild = Delete(p->Lchild, q->data);
		}
		else
		{
			q = inSucc(p->Rchild);
			p->data = q->data;
			p->Rchild = Delete(p->Rchild, q->data);
		}
	}
	return p;
}

BinaryTree::~BinaryTree()
{
	Node *p = Root;
	if (p)
	{
		inOrder(p->Lchild);
		delete p;
		inOrder(p->Rchild);
	}
}