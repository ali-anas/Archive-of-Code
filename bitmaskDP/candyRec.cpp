#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

// target bitmask - (000) -> (111)
long long solve(int like[][MAXN], int n, int c, int mask) {
	if(mask == ((1<<n)-1)) {
		return 1;
	}
	if(c >= n) {
		//cout << "mask at last" << mask << endl;
		return 0;
	}
	
	// cout << "mask: " << mask << endl;
	long long count = 0;
	for(int i = 0; i < n; i++) {
		// check if current 
		if(!(mask&(1<<i)) && like[c][i]) {
			//cout << "visited" << endl;
			count += solve(like, n, c+1, mask|(1<<i));
			//cout << "count: " << count << endl;
		}
	}
	
	return count;
}

long long iterative(int like[][MAXN], int n) {
	long long dp[1<<n];
	for(int i = 0; i < (1<<n); i++) {
		dp[i] = 0;
	}

	dp[0] = 1;

	for(int mask = 0; mask < ((1<<n)-1); mask++){
		int k = 0;
		int temp = mask;
		while( temp > 0) {
			if((temp % 2) == 1) {
				k++;
			}
			temp /= 2;
		}
		
		for(int j = 0; j < n; j++) {
			if(!(mask&(1<<j)) && like[k][j] == 1) {
				dp[mask|(1<<j)] += dp[mask];
			}
		}
		// cout << dp[mask] << " ";
	}

	return dp[(1<<n)-1];
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	//cout<< solve(like,n, 0, 0) << endl;
	cout << iterative(like, n) << endl;
	return 0;
}
