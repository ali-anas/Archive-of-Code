#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define MOD 1000000007
typedef long long ll;

bool cmp(ll a, ll b) {
	return a > b;
}

ll solve() {
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) {
		cin >> input[i];
    }

    sort(input, input+n, cmp);
    //for(int i = 0; i < n; i++) {
	//	cout << input[i] << " ";
    //}
    //cout << "\n";
    
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
		if((input[i] - i) >= 0) {
	    	input[i] = input[i] - i;
		} 
		else {
			input[i] = 0;
		}
		sum = ((sum % MOD) + (input[i]%MOD)) % MOD;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
	ll ans = solve();
	cout << ans << "\n";
    }


    return 0;
}
