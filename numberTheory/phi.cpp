#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100005

int phi[MAX];

void process_phi_to_n(int n) {

	phi[0] = 0;
	phi[1] = 1;
	
	for(int i = 2; i <= n; i++) {
		phi[i] = i;
	}
	
	for(int i = 2; i <= n; i++) {
		if(phi[i] == i) {
			for(int j = i; j <= n; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}

void solve() {
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    process_phi_to_n(n);
    for(int i = 0; i < n; i++) {
	cout << phi[i] << " ";
    }
    cout << endl;
    
    // int t;
    // cin >> t;
    // while(t--) {
    //	solve();
    // }

    return 0;
}
