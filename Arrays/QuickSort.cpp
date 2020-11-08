#include<iostream>
using namespace std;

int A[]={10,38,4,6,7,20,22,49,89,97};

int partition(int l , int h)
{
	int pivot=A[l];
	int i=l,j=h;
	while (i<j)
	{
		do
		{
			i++;
		} while (A[i]<=pivot);
		do
		{
			j--;	
		} while (A[j]>pivot);
		if (i<j)
		{
			swap(A[i],A[j]);
		}
	}
	swap(A[l],A[j]);
	return j;
}

void quick_sort(int l,int h)
{
	int j;
	if (l<h)
	{
		j=partition(l,h);
		quick_sort(l,j);
		quick_sort(j+1,h);
	}
}

int main()
{
	int n= sizeof(A)/sizeof(int);
	quick_sort(0,n-1);
	for (int i = 0; i < 10; i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}