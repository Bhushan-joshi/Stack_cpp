#include <iostream>
using namespace std;

void func1(int n)
{
	if (n>0)
	{
		func1(n-1);
		cout<<n<<endl;
	}
}

int main()
{
	int x=3;
	func1(x);
	return 0;
}
