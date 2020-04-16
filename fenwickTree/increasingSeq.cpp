#include <bits/stdc++.h>
using namespace std;
#define MOD 5000000
#define MAX 100001
typedef long long int ll;
ll BIT[51][100000];

void update(int row, int col, ll value) {
    for( ; col <= MAX; col += col&(-col)) {
        BIT[row][col] = (BIT[row][col] + value) % MOD;
    }
}

ll query(int row, int col) {
    ll sum  = 0;
    for( ; col > 0; col -= col&(-col)) {
        sum = (sum + BIT[row][col]) % MOD;
    }
    return sum;
}


int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for(int j = 1; j <= n; j++) {
        int a;
        cin >> a;
        a += 1;
    // }

    // // coordinate compression
    // set<int> s;
    // for(int i = 0; i < n; i++) {
    //     s.insert(arr[i]);
    // }
    // // map to index
    // int mpi = 1;
    // map<int, int> index;
    // set<int>::iterator it = s.begin();
    // for( ; it != s.end(); it++) {
    //     index[*it] = mpi;
    //     mpi++;
    // }

    // // change indexes
    // for(int i = 0; i < n; i++) {
    //     arr[i] = index[arr[i]];
    // }

    // for(int i = 0; i < MAX; i++) {
    //     BIT[1][i] = 1;
    // // }
    
    // for(int i = 2; i <= k; i++) {
        for(int i = 1; i <= k; i++) {
            ll value = i == 1 ? 1 : query(i-1, a-1);
            update(i, a, value);
            if(i == k) {
                ans = (ans + value) % MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}