#include <bits/stdc++.h>
using namespace std;

int getCost(int cost[4][4], int size, int p, int mask, int* memo) {
	// base case
	if(p >= size) {
		return 0;
	}
	
	if(memo[mask] != INT_MAX) {
		return memo[mask];
	}	

	int minimum = INT_MAX;
	for(int j = 0; j < size; j++) {
	// [mask][j] => [person][job]
	// if jth bit is off-then this job j is available to be assigned.
		if(!(mask&(1<<j))) {
			int smallAns = getCost(cost, size, p+1, mask|(1<<j), memo) + cost[p][j];
			if(smallAns < minimum) {
				minimum = smallAns;
			}
		}
	}
	memo[mask] = minimum;
	
	return minimum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cost[4][4] = {{7, 2, 9, 10}, {1, 8,7, 6}, {10, 11 ,12,3}, {12,11,4,6}};
	
	int* memo = new int[1<<4];	// 2^n
	for(int i = 0; i < (1<<4); i++) {
		memo[i] = INT_MAX;
	}
		
	int ans = getCost(cost, 4, 0, 0, memo); // cost, noOfPersons, personNo, mask
	cout << ans << endl;
	
	cout << memo[0] << endl;
	
	return 0;
}
