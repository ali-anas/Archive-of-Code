#include <bits/stdc++.h>
using namespace std;

int getAns(int* input, int m, int target) {
	int* dp = new int[target+1];
	for(int i = 1; i <= target; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(int i = 1; i <= target; i++) {
		for(int j = 0; j < m; j++) {
			if(i - input[j] >= 0)
			dp[i] = min(dp[i], dp[i-input[j]] + 1);
		}
	}
	int ans = dp[target];
	delete []dp;
	return ans;
}

int main() {
	int m;	// size of collection of values
	cin >> m;
	int* input = new int[m];
	for(int i = 0; i < m; i++) {
		cin >> input[i];
	}
	int target;
	cin >> target;
	int ans = getAns(input, m, target);
	cout << ans << endl;
	return 0;
}
