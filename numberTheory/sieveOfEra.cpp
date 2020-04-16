#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int count = 0;
    vector<int> sieve(n+1, 1);
    
    /*
    for(int i = 0; i <= n; i++) {
		cout << sieve[i] << " ";
	}*/
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i <= n; i++) {
		if(sieve[i]) {
			for(int j = i*i; j <=n; j += i) {
				sieve[j] = 0;
			}
		}
	} 
	
	for(int i = 1; i <= n; i++) {
		if(sieve[i]) {
			count++;
		}
	}
	
	cout << count << endl;
	return 0;
}
