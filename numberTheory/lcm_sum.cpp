#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n;
	scanf("%lld", &n);
	
	long long sum = 0;
	for(long long i = 1; i <= n; i++) {
		long long g = __gcd(i, n);
		sum = sum + ((i*n)/g);
	}
	printf("%lld\n", sum);
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
