#include <bits/stdc++.h>
using namespace std;

// long long dp[1<<22]; // 0-20
vector<int> savedMask[22];
bool visited[1<<22];
long long dp[1<<22];

long long count(int mask, int n) {

    if(mask == (1<<(n+1))-2) {
        // cout << "visited" << endl;
        return 1;
    }

    if(visited[mask])
        return dp[mask];
    // if(mask >= (1<<n)) {
    //     return 0;
    // }

    visited[mask] = 1;

    long long &ans = dp[mask];
    ans = 0;
    int val;
    for(int i = 1; i <= n; i++) {
        if(!(mask&(1<<i))) {
            // cout << "mask: " << mask << endl;
            bool valid = 1;
            for(int j = 0; j < savedMask[i].size() ; j++) {
                // cout << "i : " << i << " j : " << j << endl;
                val = savedMask[i][j];
                if(!(mask&(1<<val))) {
                    valid = 0;
                }
            }
                // mask = mask|(1<<j);
                    // cout << "mask inside: " << (mask|(1<<j)) << endl;
             if(valid) {
                ans += count(mask|(1<<i) , n);
                    // cout << "ans" << ans << endl;
            }
        }
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1; i <= 20; i++) {
        for(int j = i-1; j >= 1; j--) {
            if((i&j)==j) {
                savedMask[i].push_back(j);
            }
        }
    }
    int n;
    cin >> n;
    cout << count(0, n) << "\n";
    return 0;
}
