#include <iostream>
#include <climits>

using namespace std;

void intersection(int a1[],int a2[], int& s1, int& s2)
{
	for(int i = 0; i < s1; i++)
	{
		for(int j = 0; j < s2; j++)
		{
			if(a2[j] == a1[i])
			{
				cout << a2[j] << endl;
				a2[j] = INT_MIN;
				break;
			}
		}
	}
	return ;
}

int main()
{
	int size1 = 0, size2 = 0;
	int a1[1000000], a2[1000000];
	cin >> size1;
	for(int i = 0; i < size1; i++)
		cin >> a1[i];
	cin >> size2;
	for(int i = 0; i < size2; i++)
		cin >> a2[i];
	intersection(a1,a2,size1,size2);
	return 0;
}
