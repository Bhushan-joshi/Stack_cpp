#include<iostream>
using namespace std;


int factorial(int n)
{	
	if (n==0)
	{
		return 1;
	}
	
	return factorial(n - 1) * n;
}

int nCr(int n, int r)
{
	/**
	 * formula :- nCr=n!/(r!(n-r)!)
	 * */
	int t1,t2,t3;
	t1=factorial(n);
	t2=factorial(r);
	t3=factorial(n-r);
	return t1/(t2*t3);
}

int nCr_pascals_formula(int n,int r)
{
	/**
	 * each term is addition of previous tow terms
	 * i.e. n-1Cr-1 +n-1Cr
	 * */
	if (r==0||r==n)
	{
		return 1;
	}
	else
	{
		return nCr_pascals_formula(n-1,r-1)+nCr_pascals_formula(n-1,r);
	}
	
	
}

int main(int argc, char const *argv[])
{
	cout<<nCr(3,2)<<endl;
	cout<<nCr_pascals_formula(3,2)<<endl;

	return 0;
}
