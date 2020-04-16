#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
	int count = 0;
	for(int i = 1; i <= sqrt(n); i++) {
		if(i*i == n) {
			count++;
		}
		else if(n % i == 0) {
			count+= 2;
		}
	}
	if(count == 2) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int count = 0;
    for(int i = 1; i <= n; i++) {
		if(checkPrime(i)) {
			count++;
		}
	}
	
	cout << count << endl;
	return 0;
}
