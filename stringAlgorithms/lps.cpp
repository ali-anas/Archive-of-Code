#include <iostream>
#include <string>
using namespace std;

// O(n^2)
int getLenLPS(const string& str) {
	int max = 0;
	int n = str.length();
	for(int i = 0;i < n; i++) {
		// odd length
		int l = i;
		int r = i;
		while(l >= 0 && r < n && str[l] == str[r]) {
			int curr_len = r - l + 1;
			if(curr_len > max) {
				max = curr_len;
			}
			l--;
			r++;
		}
		
		
		// even length
		l = i;
		r = i + 1;
		while(l >= 0 && r < n && str[l] == str[r]) {
			int curr_len = r - l + 1;
			if(curr_len > max) {
				max = curr_len;
			}
			l--;
			r++;
		}
	}
	return max;
}

int main() {
	string s = "abbabbabbc";
	int len = getLenLPS(s);
	cout << len << endl;
	return 0;
}
