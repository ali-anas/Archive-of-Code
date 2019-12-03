#include <iostream>

using namespace std;

int allIndices(int a[],int size,int x, int output[])
{
	if(size == 0)
		return 0;
	int small = allIndices(a,size-1,x,output);
	if(a[size-1] == x)
	{
		output[small] = size - 1;
		return small+1;
	}
	return small;
}

int main()
{
	int o[8];
	int a[] = {1,2,3,3,4,3,2,2};
	int ans = allIndices(a,8,3,o);
	for(int i = 0; i < ans; i++)
		cout << o[i] << " ";
	return 0;
}
