#include <iostream>

using namespace std;

// basic recursive. O(2^n)
int getFibonacci1(int n) {
	if(n <= 1) {
		return n;
	}
	int smallAns1 = getFibonacci1(n-1);
	int smallAns2 = getFibonacci1(n-2);
	return smallAns1+smallAns2;
}

// helper function for getFibonacci2(n)
// memoization. O(n)
int getFibonacci2Helper(int n, int *cached) {
	if(n <=1) {
		return n;
	}
	// to check if output is already cached.
	if(cached[n] != -1) {
		return cached[n];
	}

	int smallAns1 = getFibonacci2Helper(n-1, cached);
	int smallAns2 = getFibonacci2Helper(n-2, cached);

	// cache the output for n.
	cached[n] = smallAns1 + smallAns2;

	return cached[n];
}
// O(n) - recursive
int getFibonacci2(int n) {
	int *cached = new int[n+1];
	for(int i = 0; i < n+1; i++) {
		cached[i] = -1;
	}
	int ans = getFibonacci2Helper(n, cached);
	delete []cached;
	return ans;
}

// O(n) - iterative. dp
int getFibonacci3 (int n) {
	int *cached = new int[n+1];
	cached[0] = 0;
	cached[1] = 1;
	for(int i = 2; i <= n; i++) {
		cached[i] = cached[i-1] + cached[i-2];
	}
	return cached[n];
}

int main() { 
	int n;
	cin >> n;
	cout << getFibonacci1(n) << endl;

	cout << getFibonacci2(n) << endl;

	cout << getFibonacci3(n) << endl;
	return 0;
}