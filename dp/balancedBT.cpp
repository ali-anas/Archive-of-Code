#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int balancedBT(int h) {
	ll* dp = new ll[h+1];
	dp[0] = 1;
	dp[1] = 1;

	int mod = (int) (pow(10, 9) + 7);
	for(int i = 2; i <= h; i++) {
		dp[i] = (((2 * dp[i-2] * dp[i-1]) % mod) + (dp[i-1] * dp[i-1]) % mod) % mod;
	}
	int ans = (int) dp[h];
	delete []dp;
	return ans;
}

int main() {
	int h;
	cin >> h;
	cout << balancedBT(h)<< endl;
	return 0;
}