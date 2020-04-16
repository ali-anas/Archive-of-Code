// calculates fibonacci sum
// F(m) + F(m+1) + ... + F(n)

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

void multiply(unsigned long long A[2][2], unsigned long long M[2][2]) {
    
    unsigned long long firstValue = ((A[0][0] * M[0][0]) % mod + (A[0][1] * M[1][0]) % mod) % mod ;
    unsigned long long secondValue = ((A[0][0] * M[0][1]) % mod + (A[0][1] * M[1][1]) % mod) % mod;
    unsigned long long thirdValue = ((A[1][0] * M[0][0]) % mod + (A[1][1] * M[1][0]) % mod) % mod;
    unsigned long long fourthValue = ((A[1][0] * M[0][1]) % mod + (A[1][1] * M[1][1]) % mod) % mod;
    
    A[0][0] = firstValue;
    A[0][1] = secondValue;
    A[1][0] = thirdValue;
    A[1][1] = fourthValue;
    
    return;
}

void power(unsigned long long A[2][2], unsigned long long n) {
    if(n == 1) {
        return;
    }
    
    power(A, n/2);
    multiply(A, A);
    if((n%2) != 0) {
        unsigned long long M[2][2] = {{1,1}, {1,0}};
        multiply(A, M);
    }
    
    return;
}

unsigned long long fibo(unsigned long long n) {
    if(n == 0 || n == 1) {
        return (n%mod);
    }
    
    unsigned long long A[2][2] = {{1,1}, {1,0}};
    power(A, n-1);
    return (A[0][0] % mod);
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	// Write your code here
	
	// can lead to TLE m,n <= 10^9. 1 --- 10 ^ 9
    // unsigned long long first = fibo(m);
    // if(m == n) {
    //     return first;
    // }
    // unsigned long long second = fibo(m+1);
    
    // unsigned long long ans = (first + second) % mod;
    // if(n == m+1) {
    //    return ans;
    // }
    // for(unsigned long long i = m+2; i <= n; i++) {
    //     unsigned long long currFibo = (first + second) % mod;
    //     ans = (ans + currFibo) % mod;
    //     first = second;
    //     second = currFibo;
    // }
    
    // alternate solution
    // S(n) = F(n+2)-1;
    unsigned long long nSum = fibo(n+2);
    unsigned long long m_1Sum = fibo(m+1);
    unsigned long long ans = (nSum - m_1Sum + mod) % mod;
    
    return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long m, n;
	cin >> m >> n;
	unsigned long long ans = fiboSum(m, n);
	cout << ans << endl;
	return 0;
}
	
