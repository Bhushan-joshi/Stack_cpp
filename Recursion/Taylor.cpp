#include <iostream>
using namespace std;

double e(int x, int n)
{
	static double p = 1, f = 1;
	double r;

	if (n == 0)
	{
		return 1;
	}

	r = e(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
}

double e_using_loop(int x, int n)
{
	double s = 1;
	int i;
	double num = 1;
	double den = 1;
	for(i=1;i<=n;i++)
	{
		num *= x;
		den *= i;
		s += num / den;
	}
	return s;
}
double e_using_hoenrs_formula(int x, int n)
{
	static double s;
	if (n==0)
	{
		return s;
	}
	s=1+x*s/n;
	return e_using_hoenrs_formula(x,n-1);	
}


int main(int argc, char const *argv[])
{
	cout << e(1, 100) << endl;
	cout << e_using_loop(1, 100) << endl;
	cout << e_using_hoenrs_formula(1, 100) << endl;

	return 0;
}
