/*
 * given the target value N and an array of allowed numbers,
 * count no of ways to write N as the sum of those numbers.
 * order matters
 * 1 1 2 & 1 2 1 are different combination
 * 
 * (hint : variation of coin change problem)
 */
 
#include <bits/stdc++.h>
using namespace std;

int getAns(int* arr, int n, int target) {
	int* dp = new int[target+1];
	for(int i = 0; i <= target; i++) {
		dp[i] = 0;
	}
	
	dp[0] = 1;
	for(int i = 1; i <= target; i++) {
		for(int j = 0; j < n; j++) {
			if(i-arr[j] >= 0) {
				dp[i] += dp[i-arr[j]];
			}
		}
	}
	int ans = dp[target];
	delete []dp;
	return ans;		
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i< n; i++) {
		cin >> arr[i];
	}
	int target;
	cin >> target;
	int ways = getAns(arr, n, target);
	cout << ways << endl;
	return 0;
} 
