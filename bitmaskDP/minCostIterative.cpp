// iterative solution to assigning job

#include <bits/stdc++.h>
using namespace std;

int getMinCost(int cost[4][4], const int& n) {
	int* dp = new int[(1<<n)];
	for( int i = 0; i < (1<<n); i++) {
		dp[i] = INT_MAX;
	}
	
	dp[0] = 0;
	
	for(int mask = 0; mask < ((1<<n)-1); mask++) {
		int temp = mask;
		int k = 0;
		while( temp > 0) {
			if((temp % 2) == 1) {
				k++;
			}
			temp /= 2;
		}
		
		for(int j = 0; j < n; j++) {
			if(!(mask&(1<<j))) {
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + cost[k][j]);
			}
		}
	}
	
	return dp[(1<<n)-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cost[4][4] = {{7, 2, 9, 10}, {1, 8,7, 6}, {10, 11 ,12,3}, {12,11,4,6}};
	
	int ans = getMinCost(cost, 4);
	cout << ans << endl;
	
	return 0;
}
