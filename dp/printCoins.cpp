#include <bits/stdc++.h>
using namespace std;

void getAns(int input[], int m, int target) {
	int* dp = new int[target+1];
	int* coin = new int[target+1];
	for(int i = 1; i <= target; i++) {
		dp[i] = INT_MAX;
		coin[i] = 0;
	}
	coin[0] = 0;
	dp[0] = 0;
	
	for(int i = 1; i <= target; i++) {
		for(int j = 0; j < m; j++) {
			if(i - input[j] >= 0) {
			    if(dp[i-input[j]]+1 <= dp[i]) {
			        dp[i] = dp[i-input[j]] + 1;
			        coin[i] = input[j];
			    }
			}
		}
	}
	
	int index = target;
	while(index > 0) {
		int c = coin[index];
		cout << c << " ";
		index = index - c;
	}
	
	//int ans = dp[target];
	delete []dp;
	delete []coin;
	//return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
	    int target;
	    cin >> target;
	    int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	    int m = 10;
	    //for(int i = 0; i < m; i++) {
	    //    cout << arr[i] << " ";
	    //}
	    getAns(arr, m, target);
	}
	return 0;
}
