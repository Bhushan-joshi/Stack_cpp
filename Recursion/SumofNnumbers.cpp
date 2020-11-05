#include<iostream>
using namespace  std;

int sumOfN(int n){
	if (n==0)
	{
		return 0;
	}
	else
	{
		return sumOfN(n-1)+n;
	}
	
}

int main(int argc, char const *argv[])
{
	cout<<sumOfN(5);
	return 0;
}
