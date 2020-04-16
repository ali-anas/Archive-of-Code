#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vetor<int> input;
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	int best = 0;
	int best_till = 0;
	for(int i = 0; i < n; i++) {
		best_till = max(input[i], best_till + input[i]);
		best = max(best_till, best);
	}
	
	cout << best << endl;
	return 0;
}
