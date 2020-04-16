#include <bits/stdc++.h>
using namespace std;

int modExpIter(int a, int b, int c) {
    if(a == 0 || a == 1) {
	return a%c;
    }

    if(b == 0) {
	return 1;
    }
    long ans = 1;
    while(b != 0) {
	cout <<"b: " << b;
	cout << "a: " << a << endl;
	if((b&1) == 1) {
	    ans = (ans * a) % c;
	}
	a = (a * a) % c;
	b = b / 2;
    }
    return int((ans+c)%c);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // just for sake of convenience
    if(a < 0) {
	a *= -1;
    }
    

    int ans = modExpIter(a, b, c);
    cout << ans << endl;

    return 0;
}
