#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100001
typedef long long ll;


vector<int>* createSieve() {
    bool sieve[MAX];
    for(int i = 0; i < MAX; i++) {
    	sieve[i] = true;
    }
    for(int i = 2; i*i < MAX; i++) {
		if(sieve[i]) {
	    	for(int j = i*i; j < MAX; j += i) {
				sieve[j] = false;
	    	}
		}
    }
    
    vector<int>* primes = new vector<int>();
    primes ->push_back(2);
    for(int i = 3; i < MAX; i++) {
		if(sieve[i]) {
	    	primes -> push_back(i);
		}
    }

    return primes;
}

void solve(vector<int>* &primes) {
    ll l, u;
    cin >> l >> u;
    bool isPrime[u-l+1];
    for(int i = 0; i <= u-l; i++){
		isPrime[i] = true;
    }
    
    for(int i = 0; primes->at(i) * (long long)primes->at(i) <= u; i++) {
		int currPrime = primes->at(i);
		// closest multiple of currPrime to l
		ll base = (l/(currPrime)) * (currPrime);
		if(base < l) {
	    	base += currPrime;
		}
	
		// mark all multiples within L to R as false
		for(ll j = base; j <= u; j += currPrime) {
	    	isPrime[j-l] = false;
		}
	
		// there may be a case where base is itself a prime number
		if(base == currPrime) {
	    	isPrime[base-l] = true;
		}

    }
    
    for(int i = 0; i <= u-l; i++) {
		if(isPrime[i] == true) {
	    	cout << i + l << endl;
		}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int>* primes = createSieve();
    /*for(int i = 0; i <= 10; i++) {
    cout << primes->at(i) << " ";
    }cout << "\n";*/
    int t;
    cin >> t;
    while(t--) {
    	solve(primes);
    }

    return 0;
}
