#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getKadaneSum(int *a, int n) {
    ll curr_sum = 0;
    ll max_so_far = INT_MIN;
    for(int i = 0; i < n; i++) {
        curr_sum += a[i];
        if(max_so_far < curr_sum) {
            max_so_far = curr_sum;
        }
        else {
            curr_sum = 0;
        }
    }
    return max_so_far;
}

ll maxSum(int *a, int n, int k) {
    ll kadane_sum = getKadaneSum(a, n);

    if(k == 1) {
        return kadane_sum;
    }

    ll curr_pre_sum = 0, curr_suff_sum = 0;
    ll max_pre_sum = INT_MIN, max_suff_sum = INT_MIN;

    for(int i = 0; i < n; i++) {
        curr_pre_sum += a[i];
        max_pre_sum = max(max_pre_sum, curr_pre_sum);
    }

    for(int i = n-1; i >= 0; i--) {
        curr_suff_sum += a[i];
        max_suff_sum = max(max_suff_sum, curr_suff_sum);
    }
    ll ans;
    if(curr_pre_sum < 0) {
        ans = max(max_pre_sum + max_suff_sum, kadane_sum);
    }
    else {
        ans = max(max_pre_sum + max_suff_sum + (curr_pre_sum * (k-2)), kadane_sum);
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << maxSum(a, n, k) << endl;
    }
    return 0;
}