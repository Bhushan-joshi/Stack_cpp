#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l, j = h;
	do
	{
		do
		{
			i++;
		} while (A[i] <= pivot);
		do
		{
			j--;
		} while (A[j] > pivot);
		if (i < j)
		{
			swap(A[i], A[j]);
		}
	} while (i < j);
	swap(A[l], A[j]);
	return j;
}

void quickSort(int A[], int l, int h)
{
	int j;
	if (l<h)
	{
		j=partition(A,l,h);
		quickSort(A,l,j);
		quickSort(A,j+1,h);
	}
	
}

int main(int argc, char const *argv[])
{
	int A[]={10,6,3,6,7,22,5,30,15,INT32_MAX},n=10;
	quickSort(A,0,n-1);
	for (int i = 0; i < n-1; i++)
	{
		cout<<A[i]<<endl;
	}
	
	return 0;
}
