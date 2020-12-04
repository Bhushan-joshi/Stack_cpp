#include <iostream>
using namespace std;

void ShellSort(int A[], int array_size)
{
	int gap, i, j, temp;
	for (gap = array_size / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < array_size; i++)
		{
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}