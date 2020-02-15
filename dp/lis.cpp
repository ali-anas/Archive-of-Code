#include <iostream>

using namespace std;

int getAns(int* input,const int &n) {
	int* lis = new int[n];
	lis[0] = 1;
	for(int i = 1; i < n; i++) {
		lis[i] = 1;
		for(int j = i-1; j >= 0; j--) {
			if(input[j] > input[i]) {
				continue;
			}
			int possibleAns = lis[j]+1;
			if(possibleAns > lis[i]) {
				lis[i] = possibleAns;
			}
		}
	}
	int best = 0;
	for(int i = 0; i < n; i++) {
		if(best < lis[i]) {
			best = lis[i];
		}
	}
	delete []lis;
	return best;
}

int main() {
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i= 0; i < n; i++) {
		cin >> input[i];
	}
	int ans = getAns(input, n);
	cout << ans << endl;
	delete []input;
	return 0;
}