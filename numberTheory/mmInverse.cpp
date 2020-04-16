#include <bits/stdc++.h>
using namespace std;

int mmInverse(int a, int m, int&x , int& y) {
	if(m == 0) {
		x = 1;
		y = 0;
		return a;
	}
	
	int x1, y1;
	int d = mmInverse(m, a%m, x1, y1);
	x = y1;
	y = x1 - (a/m) * y1;
	return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int x,y;
	int a = 5;
	int m = 12;
	int ans = mmInverse(a, m, x, y);
	cout << x << endl;
    return 0;
}
