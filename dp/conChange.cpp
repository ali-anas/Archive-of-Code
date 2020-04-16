/*
 * Given a value N, find the number of ways to make change for N cents,
 *  if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins.
 *  The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3},
 *  there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.
 * For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
 *  So the output should be 5.
 * (order does not matter)
 */
 
#include <bits/stdc++.h>
using namespace std;
/*
int getAns(int* arr, int m, int n) {
    int** dp = new int*[n+1];
    for(int i = 0; i < n+1; i++) {
        dp[i] = new int[m];
    }
    
    for(int i = 0; i < m; i++) {
        dp[0][i] = 1;
    }
    
    for(int i = 1; i < n+1; i++) {
        for(int j = 0; j < m; j++) {
            // including
            int x = (i - arr[j] >= 0) ? dp[i-arr[j]][j] : 0;
            // excluding
            int y = (j >=1) ? dp[i][j-1] : 0;
            
            dp[i][j] = x+y;
        }
    }
    
    int ans = dp[n][m-1];
    for(int i = 0; i < n+1; i++) {
        delete []dp[i];
    }
    delete []dp;
    return ans;
}
*/

int getAns(int* arr, int m, int target) {
	int* dp = new int[target+1];
	for(int i = 1; i <= target; i++) {
		dp[i] = 0;
	}
	
	dp[0] = 1;
	for(int i = 0; i < m; i++) {
		for(int j = arr[i]; j <= target; j++) {
			dp[j] += dp[j-arr[i]];
		}
	}
	int ans = dp[target];
	delete []dp;
	return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
	    int m;
	    cin >> m;
	    int* arr = new int[m];
	    for(int i = 0; i < m; i++) {
	        cin >> arr[i];
	    }
	    int n;
	    cin >> n;
	    
	    int ans = getAns(arr, m, n);
	    cout << ans << endl;
	    delete []arr;
	}
	return 0;
}
