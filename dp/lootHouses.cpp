#include <bits/stdc++.h>
using namespace std;

int loot(int* arr, int n) {
	int* dp = new int[n];
	dp[0] = 0;
	dp[1] = max(arr[0], arr[1]);
	for(int i = 2; i < n; i++) {
		dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
	}

	int ans = dp[n-1];
	delete []dp;
	return ans;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = loot(arr, n);
	cout << ans << endl;
	delete []arr;
	return 0;
}