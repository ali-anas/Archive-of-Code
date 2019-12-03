#include <iostream>

using namespace std;

int findunique(int *arr, int size)
{
	int ans = arr[0];
	for(int i = 1; i < size; i++)
	{
		//cout << ans << " ";
		ans = ans^arr[i];
		//cout << ans << endl;
	}
	return ans;
}

int main()
{
	int arr[1000000];
	int size; // 2n+1
	cin >> size;
	for(int i = 0; i < size; i++)
		cin >> arr[i];
	cout << "ans = " << findunique(arr,size)<<endl;
	return 0;
}
