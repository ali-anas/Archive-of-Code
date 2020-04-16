#include <iostream>
#include <string>
using namespace std;

void buildZ(int* z, string str) {
	int l = 0, r = 0;
	int n = str.length();
	for(int i = 1; i < n; i++) {
		if(i > r) {
			// i does not lies in between l & r
			// z does not exist
			l = i;
			r = i;
			while(r < n && str[r-l] == str[r]) {
				r++;
			}
			z[i] = r - l;
			r--;
		} else {
			int k = i - l;
			if(z[k] <= r - i) {
				// i lies in between l & r
				// and z will exist previously
				z[i] = z[k];
			} else {
				// some part of z is included
				// have to check for further match
				l = i;
				while(r < n && str[r-l] == str[r]) {
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
	}
}

void zAlgo(const string& text, const string& pattern) {
	string str = pattern + "$" + text;
	int patLen = pattern.length();
	int n = str.length();
	int* z = new int[n];
	z[0] = 0;
	buildZ(z, str);
	for(int i = 0; i < n; i++) {
		if(z[i] == patLen) {
			cout << i - patLen - 1 << endl;
		}
	}
}

int main() {
	string text = "abcdsafbcdfasbcda";
	string pattern = "bcd";
	zAlgo(text, pattern);
	return 0;
}
