#include <iostream>
using namespace std;

int findMax(int A[], int size)
{
	int max = INT32_MIN;
	for (int i = 0; i < size; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void countSort(int A[], int sizeof_array)
{
	int max, i, j;
	int *c;
	max = findMax(A, sizeof_array);
	c = new int[max + 1];
	for (i = 0; i < max + 1; i++)
		c[i] = 0;
	for (i = 0; i < sizeof_array; i++)
		c[A[i]]++;
	i = j = 0;
	while (j < max + 1)
	{
		if (c[j] > 0)
		{
			A[i++] = j;
			c[j]--;
		}
		else
		{
			j++;
		}
	}
}