#include <iostream>

using namespace std;

bool checkMember(int n)
{
	int fib2 = 1;
	int fib1 = 0;
	while(fib2 <= n)
	{
		if(fib2 == n)
		{
			return true;
		}
		int temp = fib2;
		fib2 = fib2+fib1;
		fib1 = temp;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	if(checkMember(n))
		cout << "true"<<endl;
	else
		cout << "false"<<endl;
	return 0;
}
