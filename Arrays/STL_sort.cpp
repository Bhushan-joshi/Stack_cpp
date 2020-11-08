#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int A[]={19,49,30,2,45,22,40,20};
	int n=sizeof(A)/sizeof(A[0]);
	sort(A,A+n);
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}