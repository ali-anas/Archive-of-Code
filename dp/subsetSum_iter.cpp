#include <iostream>
using namespace std;

bool subsetSum(int* val, int n, int sum) {
	bool** dp = new bool*[n+1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new bool[sum+1];
	}

	for(int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}

	for(int i = 1; i <= sum; i++) {
		dp[0][i] = false;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			// not including
			dp[i][j] = dp[i-1][j];

			if(j >= val[i-1]) {
				// including
				dp[i][j] = dp[i][j] || dp[i-1][j-val[i-1]];
			}
		}
	}
	bool ans = dp[n][sum];
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
	for(int i = 0; i < n; i++) {
		cin >> val[i];
	}
	int sum;
	cin >> sum;
	if(subsetSum(val, n, sum)) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	return 0;
}