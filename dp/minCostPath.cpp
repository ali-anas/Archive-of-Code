#include <bits/stdc++.h>
using namespace std;

int minCostPath(int** input, int n, int m) {
	int** dp = new int*[n];
	
	for(int i = 0; i < n; i++) {
		dp[i] = new int[m];
	}
	dp[0][0] = input[0][0];
	// first row
	for(int i = 1; i < m; i++) {
		dp[0][i] = input[0][i] + dp[0][i-1];
	}

	// first column
	for(int i = 1; i < n; i++) {
		dp[i][0] = input[i][0] + dp[i-1][0];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			dp[i][j] = input[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
		}
	}

	int ans = dp[n-1][m-1];
	for(int i = 0; i < n; i++) {
		delete []dp[i];
	}
	delete []dp;
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	int** input = new int*[n];
	for(int i = 0; i < n; i++) {
		input[i] = new int[m];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	int ans = minCostPath(input, n, m);
	cout << ans << endl;

	for(int i = 0; i < n; i++) {
		delete []input[i];
	}
	delete []input;
}