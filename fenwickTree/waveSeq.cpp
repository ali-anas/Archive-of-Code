#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 100001
typedef long long int ll;

int BIT[MAX][3];
int n;
int input[MAX], dp[MAX];

int update(int value, int col, int index) {
    for( ; index <= n; index += index&(-index)) {
        BIT[index][col] = (BIT[index][col] + value) % MOD;
    }
}

int query(int index, int col) {
    int sum = 0;
    for( ; index > 0; index -= index&(-index)) {
        sum = (sum + BIT[index][col]) % MOD;
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxVal = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> input[i];
        if(maxVal < input[i]) {
            maxVal = input[i];
        }
    //   for(int i = 1; i <= n; i++) {
        int a = query(input[i]-1, 0) + query(input[i-1], 2);
        int b = query(maxVal, 1) - query(input[i], 1) + query(maxVal, 2) - query(input[i], 2);
        dp[i] = (a + b) % MOD;
        update(b, 1, input[i]);
        update(a, 0, input[i]);
        update(1, 2, input[i]);
    // }
    }
    for(int i = 1; i <=40 ; i++) {
        cout << BIT[i][0] << " " << BIT[i][1] << "\n";
    }
    int ans = 0;
    int t = 100000;
    // while(t > 0) {
    //     ans = (ans + BIT[t][0]) % MOD;
    //     ans = (ans + BIT[t][1]) % MOD;
    //     t -= (t&(-t));
    // }
    // cout << ans << endl;
    // // for(int i = 1; i <= n; i++) {
    // //     cout << dp[n] << "\n";
    // // }
    return 0;
}