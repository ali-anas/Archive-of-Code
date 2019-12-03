#include <iostream>

using namespace std;

bool isSorted(int a[], int size = 8)
{
	if(size == 0 || size == 1)
		return true;
	if(a[0]>a[1])
		return false;
	bool sorted = isSorted(a+1,size-1);
	return sorted;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	cout << isSorted(a) << endl;
}
