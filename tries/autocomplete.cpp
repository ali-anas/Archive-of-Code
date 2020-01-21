/*
	Givan n number of words and an incomplete word w.
	You need to auto-complete that word w.
	That means, find and print all the possible words which 
	can be formed using the incomplete word w.

	Input Format :
		Line 1 : Integer n
		Line 2 : n words (separated by space)
		Line 3 : Word w
	Output Format :
		All possible words (in different lines)

	Sample Input :
		7
		do dont no not note notes den
		no
	Sample Output :
		no
		not
		note
		notes
 */

#include <iostream>
using namespace std;

#include "trie.h"


int main() {
	trie t;
    int N;
    cin >> N;
    string pattern;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        t.insertWord(word);
    }
    cin >> pattern;
    t.autoComplete(pattern);
    return 0;
}