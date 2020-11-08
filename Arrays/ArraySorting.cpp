#include<iostream>
using namespace std;

int main()
{
	int A[]={11,23,37,1,93,10,8,290,22};
	int min_idx=0;
	for (int i = 0; i < 9; i++)  
    {  
        min_idx = i;  
        for (int j = i+1; j < 9; j++)  
        if (A[j] < A[min_idx])  
            min_idx = j;  
        swap(A[min_idx], A[i]);  
    }  
	for (int k = 0; k < 9; k++)
	{
		cout<<A[k]<<endl;
	}
	
	return 0;
}