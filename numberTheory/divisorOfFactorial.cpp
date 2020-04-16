#include <bits/stdc++.h>
using namespace std;

#define MAX 500002
#define mod 1000000007


vector<int>* createSieve() {

    vector<int>* primes = new vector<int>();
    vector<int> sieve(MAX, 1);

    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i <= MAX; i++) {
	if(sieve[i]) {
	    for(int j = i*i; j <= MAX; j += i){
		sieve[j] = 0;
	    }
	}
    }

    primes -> push_back(2);
    for(int i = 3; i <= MAX; i += 2) {
	if(sieve[i]) {
	    primes -> push_back(i);
	}
    }

    return primes;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>* primes = createSieve();
    //for(int i = 0; i <= 10; i++) {
    //cout << sieve[i] << " ";
    //}
    int t;
    cin >> t;
    while(t--) {
	int n;
	cin >> n;
	
	//cout << "visited1" << endl;
	long long ans = 1;
	for(int i = 0; primes -> at(i) <= n; i++) {
		int prime = primes -> at(i);
		//cout << "visited2" << endl;
		long long x = 0;
		//int k = getPowerLimit(prime, n);
		while((n/prime) != 0) {
		    x = ( x + (n/prime)) % mod;
		    prime = prime * primes -> at(i);
		}

		//cout << "visited3" << endl;
		ans = (((ans) % mod) * ((x+1) % mod)) % mod;
	}
	cout << ans << endl;
    }
    
    return 0;
}
