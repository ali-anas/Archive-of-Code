#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// recursive.
int getMinStepsTo1 (int n) {
	if(n == 1) {
		return 0;
	}

	int mod3 = n;
	int mod2 = n;
	int dec1 = n;
	if((n % 3) == 0) {
		mod3 = getMinStepsTo1(n/3);
	}

	if((n%2) == 0) {
		mod2 = getMinStepsTo1(n/2);
	}

	dec1 = getMinStepsTo1(n-1);

	return min(mod3, min(mod2, dec1))+1;
}


// ----------------------------------------------------------------------------------------
// O(n) memoization.
// heplper funciton to countStepsTo1(n).
int countHelper(int n, int *cached) {
    if(n <= 1) {
        return 0;
    }
    
    if(cached[n] != -1) {
        return cached[n];
    }
    
    int mod2 = INT_MAX;
    int mod3 = INT_MAX;
    
    if((n%3) == 0) {
        mod3 = countHelper(n/3, cached);
    }
    
    if((n%2) == 0) {
        mod2 = countHelper(n/2, cached);
    }
    
    int diff1 = countHelper(n-1, cached);

    int ans = min(mod3, min(mod2, diff1))+1;
    cached[n] = ans;
    
    return ans;
}

int countStepsTo1(int n){
    int* cached = new int[n+1];
    for(int i = 0; i < n+1; i++) {
        cached[i] = -1;
    }
    int ans = countHelper(n, cached);
    delete []cached;
    return ans;
}
// ------------------------------------------------------------------------------------------

int main() {
	int n;
	cin >> n;
	cout << getMinStepsTo1(n) << endl;

	cout << countStepsTo1(n) << endl;
	return 0;
}