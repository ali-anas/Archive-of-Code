#include <bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c) {
    if(a == 0 || b == 1) {
	return a;
    }

    if(b == 0) {
	return 1;
    }

    long ans;
    if((b%2) == 0) {
	long smallAns = modExp(a, b/2, c);
	ans = (smallAns * smallAns) % c;
    }
    else {
	long smallAns = modExp(a, b-1, c);
	// a can be greater than c
	ans = (a % c);
	ans = (ans * smallAns) % c;
    }
    
    // ans can be negative so change it to +ve
    // -ve -> if b is odd then (a -> -ve)  a* smallAns -> -ve
    return int((ans+c) % c);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // just for sake of convenience
    if(a < 0) {
	a *= -1;
    }
    

    int ans = modExp(a, b, c);
    cout << ans << endl;

    return 0;
}
