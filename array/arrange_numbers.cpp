#include <iostream>

using namespace std;

void rearrange(int a[],int n)
{
	int i = n;
	int index = 0;
	int j = 1;
	while(j <= n)
	{
		if(j%2 != 0)
		{
			a[index] = j;
			index++;
		}
		j++;
	}
	while(i >= 2)
	{
		if(i%2 == 0)
		{
			a[index] = i;
			index++;
		}
		i--;
	}
}

int main()
{
	int a[1000000];
	int n;
	cin >> n;
	rearrange(a,n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
