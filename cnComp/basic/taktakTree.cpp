// problem -> orac.amt.edu.au/cgi-bin/train/problem-pl?problemid=382&set=simple2

#include <bits/stdc++.h>
using namespace std;

bool equallyDistributed(int fruits) {
	if((fruits % 11) == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	// take input from input file.
	// write output to output file.
	// freopen("taktakin.txt","r",stdin);
	// freopen("taktakout.txt","w",stdout);

	// take input
	int fruits;
	cin >> fruits;
	int moonCounts = 0;
	while(!equallyDistributed(fruits)) {
		moonCounts += 1;
		fruits = 2 * fruits;
	}

	cout << moonCounts << " " << fruits << endl;

	return 0;
}