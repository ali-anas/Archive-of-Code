#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    char s[100005];
    cin>>s;
    int n = strlen(s);
    int ans = 0, preAns = 0;
    for(int i = 0; i < n; i++) {
        int curr = 'Z' - s[i];
        ans = (ans + curr + (long long)preAns * curr) % MOD;
        preAns = (curr + (long long)26 * preAns) % MOD;
    }

    cout << ans << endl;
    return 0;
}