#include <bits/stdc++.h>
using namespace std;

int* getLps(string pattern) {
	int len = pattern.length();
	int* lps = new int[len];
	lps[0] = 0;
	int j = 0, i = 1;
	while (i < len) {
		if(pattern[i] == pattern[j]) {
			lps[i] = j+1;
			i++;
			j++;
		} else {
			if (j != 0) {
				 j = lps[j-1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

bool kmpSearch(string text, string pattern) {
	int textLen = text.length();
	int patLen = pattern.length();
	int* lps = getLps(pattern);
	int i = 0;
	int j = 0;
	while(i < textLen && j < patLen) {
		if(text[i] == pattern[j]) {
			i++;
			j++;
		} else {
			if(j != 0) {
				j = lps[j-1];
			} else {
				i++;
			}
		}
	}
	delete []lps;
	if(j == patLen) {
		return true; // return (i-patLen) for first index
	}
	return false; // else return -1 (not found)
}

int main() {
	string str = "WelcomeBack";//"abcxabcdabcdabcy";
	string subString = "come";//"abcdabcyx";
	cout << kmpSearch(str, subString) << endl;
	return 0;
}
