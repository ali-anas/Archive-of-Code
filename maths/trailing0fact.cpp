#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		ll count = 0;
		for(ll i = 5;  n/i >= 1; i*=5) {
			count += n/i;
		}
		
		printf("%lld\n", count);
	}
	return 0;
}