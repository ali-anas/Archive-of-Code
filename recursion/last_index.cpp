#include <iostream>

using namespace std;

int lastIndex(int arr[],int size,int x)
{
	if(size == 0)
		return -1;
	int smallAns = lastIndex(arr+1, size-1, x);
	if(smallAns == -1)
	{
		if(arr[0] == x)
			return 0;
		else
			return -1;
	}
	return smallAns+1;
}

int main()
{
	int arr[] = {2,3,4,3,5,3,4,2};
	cout << lastIndex(arr,8,3);  // lastIndex(array, size, number_to_find_position
	return 0;
}
