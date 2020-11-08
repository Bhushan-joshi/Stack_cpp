#include <iostream>
using namespace std;

int main()
{
	int A[] = {29, 84, 3, 84, 9, 43, 90, 22, 10};
	int l = 9;
	bool isSorted = false;
	while (!isSorted)
	{
		isSorted = true;
		for (int i = 0; i < l - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				swap(A[i], A[i + 1]);
				isSorted = false;
			}
		}
	}
	for (int j = 0; j < l - 1; j++)
	{
		cout << A[j] << endl;
	}

	return 0;
}
