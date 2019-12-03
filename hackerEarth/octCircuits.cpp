#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
/*
int calculateperm(int n)
{
    int prod = 1;
    while(n>=2)
    {
        prod = prod*n;
        n--;
    }
    return prod;
}

int main()
{
    int t;
    cin >> t;
    while(t>0)
    {
        int sum = 0;
        int n;
        cin >> n;
        int totalperm = calculateperm(n);
        for(int i = 1; i <= n; i++)
        {
            sum = sum + (n-i);
        }
        cout << sum * totalperm;
        t--;
    }
    return 0;
}*/
ll togglebit(ll n)
{
    if (n == 0)
        return 1;

    // Make a copy of n as we are
    // going to change it.
    ll i = n;

    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return i ^ n;
}

// Returns XNOR of num1 and num2
ll XNOR(ll num1, ll num2)
{
    // if num2 is greater then
    // we swap this number in num1
    if (num1 < num2)
        swap(num1, num2);
    num1 = togglebit(num1);

    return num1 ^ num2;
}
int main()
{
    long long x ,y;
    //scanf("%d%d",&x,&y);
    //printf("%d",x ^ y);
    cin >> x >> y;
    ll XOR = ll(x^y);
    cout << "XOR : " << XOR << endl;
    ll xnor = ll(XNOR(x,y));
    cout << "xnor : " << xnor <<endl;
    cout << max(XOR,xnor);
    //cout << int(~(x ^ y));
    return 0;
}
/*

*/
