#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
struct Node *head = nullptr;

void InsertELE(int ele)
{
	struct Node *new_ele = new Node;
	new_ele->data = ele;
	new_ele->next = head;
	head = new_ele;
}

void display()
{
	struct Node *ptr = head;
	while (ptr)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}

int totalElement()
{
	int tnum = 0;
	struct Node *ptr = head;
	while (ptr)
	{
		tnum++;
		ptr = ptr->next;
	}
	return tnum;
}
int sumElement()
{
	int sum = 0;
	struct Node *ptr = head;
	while (ptr)
	{
		sum = sum + ptr->data;
		ptr = ptr->next;
	}
	return sum;
}
int max()
{
	struct Node *ptr = head;
	int max = ptr->data;
	while (ptr)
	{
		if (max < ptr->data)
		{
			max = ptr->data;
		}

		ptr = ptr->next;
	}
	return max;
}

Node * Search(int num)
{
	//binary search is not good ...caz we have to go to mid and that takes n/2 time
	struct Node *ptr=head;
	while (ptr!=NULL)
	{
		if (ptr->data==num)
		{
			return ptr;
		}
		ptr=ptr->next;
	}
}

int main(int argc, char const *argv[])
{
	InsertELE(10);
	InsertELE(20);
	InsertELE(30);
	InsertELE(40);
	display();
	cout << totalElement() << endl;
	cout << sumElement() << endl;
	cout << max() << endl;
	cout <<"elemeny found at:-"<< Search(40) << endl;

	return 0;
}
