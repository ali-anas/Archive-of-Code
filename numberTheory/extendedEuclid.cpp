#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
	if(b==0) {
		x = 1;
		y = 0;
		return a;
	}
	
	int x1, y1;
	int d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b) * y1;
	return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int a = 15;
    int b = 10;
    int x, y;
    
    int ans = gcd(a, b, x, y);
    cout << ans << endl;
    cout << x << "\n" << y << endl;

    return 0;
}
