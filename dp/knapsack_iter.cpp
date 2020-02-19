#include <iostream>

using namespace std;

int knapsack(int* wt, int* val, int W , int n) {
	int** dp = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int[W+1];
	}

	for(int i = 0; i <= W; i++) {
		dp[0][i] = 0;
	}

	for(int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int w = 0; w <= W; w++) {
			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w) {
				dp[i][w] = max(dp[i][w], val[i-1]+dp[i-1][w-wt[i-1]]);
			}
		}
	}

	int ans = dp[n][W];
	for(int i = 0; i <= n; i++) {
		delete []dp[i];
	}
	delete []dp;
	return ans;
}

int main() {
	int n;
	cin >> n;
	int* val = new int[n];
	int* wt = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> wt[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> val[i];
	}

	int W;
	cin >> W;
	cout << knapsack(wt, val, W, n) << endl;
	delete []wt;
	delete []val;
	return 0;

}