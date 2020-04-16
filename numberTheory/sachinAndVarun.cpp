#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

ll mmInverse(ll a, ll m, ll& x, ll& y) {
    if(m == 0) {
	x = 1;
	y = 0;
	return a;
    }

    ll x1, y1;
    ll d = mmInverse(m, a%m, x1, y1);
    x = y1;
    y = x1 - (a/m) * y1;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
	ll x, y, a, b, d;
	cin >> a >> b >> d;
	ll g = __gcd(a, b);
	// special cases
	if(d % g) {
	    cout << 0 << endl;
	    continue;
	}
	if(d == 0) {
	    cout << 1 << endl;
	    continue;
	}
	a /= g;
	b /= g;
	d /= g;
	ll makeX = mmInverse(b, a, x, y);
	x = (x % a + a) % a;
    	ll y0 = ( (d%a) * x) % a;
	if(d < y0*b) {
	    cout << 0 << endl;
	    continue;
	}
	ll firstValue = d/b;
	ll n = (firstValue - y0) / a;

	ll ans = n + 1;
	cout << ans << endl;
    }
    return 0;
}
