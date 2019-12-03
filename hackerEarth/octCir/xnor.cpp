#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll togglebit(ll n)
{
    if (n == 0)
        return 1;
    ll i = n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return i ^ n;
}

ll XNOR(ll num1, ll num2)
{
    if (num1 < num2)
        swap(num1, num2);
    num1 = togglebit(num1);

    return num1 ^ num2;
}

ll findmax(ll f0, ll f1, ll e0, ll e1, ll n)
{
    ll i = 2;
    ll f2;
    ll e2;
    for(; i < n; i++)
    {
        f2 = f0^f1;
        f0 = f1;
        f1 = f2;
        e2 = XNOR(e1, e0);
        e0 = e1;
        e1 = e2;
    }
    return max(f1,e1);
}

int main()
{
    int t;
    cin >> t;
    while(t>0)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        //ll *f = new ll[n+1];
        //ll *e = new ll[n+1];
        ll f0 = a;
        ll f1 = b;
        ll e0= a;
        ll e1 = b;
        ll ans;
        //cout << "hello main1" << endl;
        if(n > 0)
        {
            ans = findmax(f0, f1, e0, e1, n);
        }
        else
        {
            ans = max(a^b,XNOR(a,b));
        }

        cout << ans << "\n";
        t--;
    }
    return 0;
}
