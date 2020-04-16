/*
 * Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
 * That is, if N is 4, then we can represent it as : 
 * {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
 */

#include<bits/stdc++.h>
using namespace std;

int minCount(int n) {
	if(n <= 1) {
		return 1;
	}
	int least = INT_MAX;
	for(int i = 1; i <= sqrt(n); i++) {
		int ans = minCount(n-(i*i));
		least = min(least, ans);
	}
	return least+1;
}

int minCountDP(int n) {
	int*dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= n; i++) {
		dp[i] = i;
		for(int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], 1 + dp[i- (j*j)]);
		}
	}
	int ans = dp[n];
	delete []dp;
	return ans;
}

int main(){
    
    int num;
    cin >> num;
    //cout << minCount(num) << endl;
    cout << minCountDP(num) << endl;
    return 0;
}