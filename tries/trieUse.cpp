#include <iostream>

using namespace std;
#include "trie.h"

int main() {
	trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("not");

	cout << t.find("and") << endl;

	t.removeWord("and");
	cout << t.find("and") << endl;

	return 0;
}