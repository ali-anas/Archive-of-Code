/*
 * Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
 * That is, if N is 4, then we can represent it as : 
 * {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
 */

#include<bits/stdc++.h>
using namespace std;

int minCount(int n) {
	if(n <= 1) {
		return 1;
	}
	int least = INT_MAX;
	for(int i = 1; i <= sqrt(n); i++) {
		int ans = minCount(n-(i*i));
		least = min(least, ans);
	}
	return least+1;
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}