#include<bits/stdc++.h>
using namespace std;

void mutiply(int A[2][2], int M[2][2]) {

    int firstValue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
    int secondValue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
    int thirdValue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
    int fourthValue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

    A[0][0] = firstValue;
    A[0][1] = secondValue;
    A[1][0] = thirdValue;
    A[1][1] = fourthValue;
    return;
}

void power(int A[2][2], int n) {
    // base case
    if(n == 1) {
	return;
    }

    power(A, n/2);

    // multiply A^(n/2) * A^ (n/2)
    mutiply(A, A);

    // if n is odd
    if((n%2) != 0) {
	int M[2][2] = {{1,1}, {1,0}};
	mutiply(A, M);
    }

    return;
}

// uses matrix exponentiation method
int fibo(int n) {
    if(n == 0 || n == 1) {
	return n;
    }
    int A[2][2] = {{1,1}, {1,0}};

    power(A, n-1);
    return A[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
