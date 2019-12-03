#include <iostream>
using namespace std;
int main()
{
	char arr[15];
	cin.getline(arr,8);
	int i = 0;
	while(arr[i] != '\0')
	{
	cout<< arr[i];
	i++;
	}
	return 0;
}
