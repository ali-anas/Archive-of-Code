#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 1000000

int input[MAX];
int sieve[MAX];

void initializeSieve() {
    for(int i = 0; i < MAX; i++) {
	sieve[i] = 0;
    }
    return;
}

void createValues() {
    for(int i = 1; i*i < MAX; i++) {
	if(sieve[i] > 0) {
	    for(int j = 2 * i; j < MAX; j += i) {
		if(sieve[j] > 0) {
		    sieve[j] = ((sieve[j]%MOD) + (sieve[i]%MOD)) % MOD;
		}
	    }
	}
    }
    return;
}

void solve() {
    initializeSieve();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
	scanf("%d", &input[i]);
    }
    sort(input, input+n);
    for(int i = 0; i < n; i++) {
	sieve[input[i]] = 1;
    }

    createValues();

    int sum = 0;

    for(int i = 1; i < MAX; i++) {
	if(sieve[i] > 0) {
	    sum = ((sum%MOD) + (sieve[i]%MOD)) % MOD;
	}
    }
    printf("%d\n", sum);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
    	solve();
    }

    return 0;
}
