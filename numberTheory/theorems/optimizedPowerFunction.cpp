#include <bits/stdc++.h>
using namespace std;

int optimizedPowerFunction(int x, int n) {
    if(n == 0) {
	return 1;
    }

    if(n == 1) {
	return x;
    }

    int half = n / 2;
    int value = optimizedPowerFunction(x, half);
    return value * value;
}

// 0(log n)
int optimized_sol(int x, int n) {
    if(x == 0 || x == 1) {
	return x;
    }
    if(n % 2 == 0) {
	return optimizedPowerFunction(x, n);
    }
    else {
	return x * optimizedPowerFunction(x, n-1);
    }
}

int main() {
    int x, n;
    cin >> x >> n;
    int ans = optimized_sol(x, n);
    cout << ans << endl;
    return 0;
}
