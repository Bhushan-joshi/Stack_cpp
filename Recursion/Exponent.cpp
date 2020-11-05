#include <iostream>
using namespace std;

int pow(int m, int n)
{
	/**
	 * this function use old way this may use longer time
	 * */
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return pow(m, n - 1) * m;
	}
}

int pow_adv(int m, int n)
{
	/**
	 * This function use advance way to reduce function calls 
	 * this reduces the time and space complxity
	 * */
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return pow_adv(m * m, n / 2);
	}
	else
	{
		return m * pow_adv(m * m, (n - 1) / 2);
	}
}

int main(int argc, char const *argv[])
{
	cout<<pow(3,3)<<endl;
	cout<<pow_adv(3,3)<<endl;
	return 0;
}
