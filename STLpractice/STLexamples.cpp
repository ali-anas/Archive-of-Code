#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// remove duplicates

vector<int> removeDuplicates(vector<int> input) {
	vector<int> ans;
	set<int> s;
	for(int i = 0; i < input.size(); i++) {
		if(s.find(input[i]) == s.end()) {
			s.insert(input[i]);
			ans.push_back(input[i]);
		}
	}

	return result;
}

// return first non-repeating character.

char nonRepeatingCharacter(string s) {
	map<char,int> freq;

	for(int i = 0; i < str.length(); i++) {
		char currChar = s[i];
		freq[currChar]++;
	}

	for(int i = 0; i < str.length(); i++) {
		if(freq[s[i]] == 1) {
			return s[i];
		}
	}
	return s[0];
}
