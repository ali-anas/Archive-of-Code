class trieNode {
	public :
	char data;
	trieNode **children;
	bool isTerminal;

	// constructor
	trieNode(char data) {
		this -> data = data;
		/*
			assuming our trie take small case alphabets
			as input.
		 */
		children = new trieNode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		
		isTerminal = false;
	}
};