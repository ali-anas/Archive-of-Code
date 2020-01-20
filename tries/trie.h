#include <string>

#include "trieNode.h"
/*
		char data;
		trieNode **children;
		bool isTerminal;

		// constructor
		trieNode(char data) {
		this -> data = data;
		
		// assuming our trie take small case alphabets
		// as input.
		 
		children = new trieNode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		
		isTerminal = false;
 */

class trie {
private:
	trieNode *root = NULL;
	/*
		helper function for insertWord (string)
		takes root and word as args.
		return nothing.
		inserts data(string) into trie recursively.
	 */
	void insertHelper (trieNode* root , string word) {
		// base case.
		// reached end of word.
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		int index = word[0] - 'a';
		trieNode *child;
		if(root -> children[index] != NULL) {
			// if child with data word[0] exist.
			child = root -> children[index];
		} else {
			// if child with data word[0] does not exist
			child = new trieNode(word[0]);
			root -> children[index] = child;
		}

		// recursive call
		// the child becomes the root for further data in words.
		insertHelper(child, word.substr(1));
		return;
	}


	bool findHelper (trieNode* root, string word) {
		if (word.size() == 0) {
			return root -> isTerminal;
		}

		int index = word[0] - 'a';
		if(root -> children[index] == NULL) {
			return false;
		}
		else {
			trieNode* child = root -> children[index];
			return findHelper (child, word.substr(1));
		}
	}



	void removeHelper (trieNode* root, string word) {
		if(word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		trieNode* child;

		if(root -> children[index] != NULL) {
			// character in word matches.
			child = root -> children[index];
		} else {
			// character in word does not match.
			return;
		}

		// recursive call
		removeHelper (child, word.substr(1));

		// to delete characters which are not useful in trie
		// after we changed isTerminal configurations of nodes.

		if (child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					// there exists some useful character after this child(node).
					return;
				}
			}
			// the trash node is found (which is current node(child),
			// because it does not have any child further and even it is not 
			// a terminal node).
			delete child;
			root -> children[index] = NULL;
		}

	}

public:
	trie () {
		root = new trieNode('\0');
	}

	void insertWord (string word) {
		insertHelper(root , word);
	}

	bool find (string word) {
		return findHelper (root, word);
	}

	void removeWord (string word) {
		removeHelper (root , word);
	}
};