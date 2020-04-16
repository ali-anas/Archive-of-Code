// fist ten primes 2, 3, 5, 7, 11, 13, 17, 19, 23, 29

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    cin >> n >> w;
    pair<long long, long long>* input = new pair<long long, long long>[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i].first >> input[i].second;
    }
    sort(input, input+n);

    long long*** dp = new long long**[2];
    for(int i = 0; i < 2; i++) {
        dp[i] = new long long*[n+1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = new long long[w+1];
            for(int k = 0; k <= w; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    int primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    // base case
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            dp[0][i][j] = dp[0][i-1][j];
            if(j >= input[i-1].second) {
                dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-input[i-1].second] + input[i-1].first);
            }
        }
    }

    // computation
    for(int prime = 1; prime <= 10; prime++) {
        int flag = prime%2;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= w; j++) {
                dp[flag][i][j] = dp[flag][i-1][j];
                if(j >= input[i-1].second) {
                    dp[flag][i][j] = max(dp[flag][i][j], max(dp[flag][i-1][j-input[i-1].second]+input[i-1].first,
                        dp[flag^1][i-1][j-input[i-1].second] + input[i-1].first * primes[prime]));
                }
            }
        }
    }

    cout << dp[0][n][w] << endl;


    return 0;
}