#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;
	long* a = new long[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long i = 0;
	long ans = 0;
	while(i < n-1) {
		long j = i+1;
		while(j < n-1) {
			if(abs(a[i]) > abs(a[j]) || ((abs(a[i]) == abs(a[j])) && a[i] > 0)) {
				break;
			}
			else {
				j++;
			}
		}
		ans +=  ((j-i) * a[i]) + ((j*j - i*i) * (a[i] * a[i]));
		i = j;
	}

	cout << ans << endl;
	return 0;
}
