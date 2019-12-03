 #include <bits/stdc++.h>

using namespace std;

void findmaxsum(int a[],const int &n)
{
	int best = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			int sum = 0; 
			for(int k = i; k <= j; k++)
			{
				sum += a[k];
			}
			best = max(best,sum);
		}
	}
	cout << "max sum : " << best << "\n";
	return;
}

int main()
{
	int a[]= {-1,2,4,-3,5,2,-5,2};
	findmaxsum(a,8);
	return 0;
}
