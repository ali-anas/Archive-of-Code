#include <iostream>
using namespace std;

int main()
{
	//int a = 7;
	int a[10];
	a[0] = 5;
	a[1] = 10;
	a[2] = 15;
	cout << a << endl;
	cout << &a <<endl;
	cout << &a[0] <<endl;
	cout << a[0] << endl;
	cout << *a << endl;
	cout << a[1] << endl;
	cout << *(a+1) << endl;
	cout << 1[a] << endl;
	return 0;
}
