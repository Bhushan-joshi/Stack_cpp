#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int fib_loop(int n)
{
	int t0 = 0, t1 = 1, s = 0;
	if (n <= 1)
	{
		return n;
	}
	for (int i = 2; i <= n; i++)
	{
		s = t0 + t1;
		t0 = t1;
		t1 = s;
	}
	return s;
}

int f[10];
int mfib(int n)
{
	//reduces the function calls
	if (n<=1)
	{
		f[n]=n;
		return n;
	}else
	{
		if (f[n-2]==-1)
		{
			f[n-2]=mfib(n-2);
		}if (f[n-1]==-1)
		{
			f[n-1]=mfib(n-1);
		}	
		f[n]=f[n-2]+f[n-1];		
		return f[n-2]+f[n-1];	
	}
	
	
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		f[i]=-1;
	}
	
	cout << mfib(7) << endl;
	return 0;
}