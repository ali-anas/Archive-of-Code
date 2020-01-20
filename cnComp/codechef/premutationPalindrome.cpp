#include <bits/stdc++.h>

using namespace std;

char getchar(int i) {
	return char(i+97);
}

void printPalindromic(string s) {
	map<char, vector<int> > indexes;
	for(int i = 0; i < s.length(); i++) {
		indexes[s[i]].push_back(i);
	}

	int odd_freq_char = 0;
	for(int i = 0; i < 26; i++) {
		if((indexes[getchar(i)].size() % 2) != 0) {
			odd_freq_char++;
		}
	}

	if(odd_freq_char >= 2) {
		cout << "-1";
		return;
	}

	int ans[s.length()];
	int start = 0;
	int end = s.length()-1;

	for(int i = 0; i < 26; i++) {
		char curr_char = getchar(i);
		for(int j = 0; j < indexes[curr_char].size(); j+=2) {
			if((indexes[curr_char].size() - j) == 1) {
				ans[s.length()/2] = indexes[curr_char][j];
				continue;
			}
			ans[start] = indexes[curr_char][j];
			ans[end] = indexes[curr_char][j+1];
			start++;
			end--;
		}
	}

	for(int i = 0; i < s.length(); i++) {
		cout << ans[i] + 1 << " ";
	}

	return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		printPalindromic(s);
		cout << endl;
	}
	return 0;
}

/*
3
aa
abc
abab
*/