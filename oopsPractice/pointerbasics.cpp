#include <iostream>
using namespace std;
int main()
{
	char a;
	char *ptrA;
	char **ptrPtrA;
	ptrA= &a;
	ptrPtrA = &ptrA;
	cin>>a;

	cout << *(*ptrPtrA);
	cout << endl;
	return 0;
}
