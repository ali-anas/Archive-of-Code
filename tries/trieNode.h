class trieNode {
	public :
	char data;
	trieNode **children;
	bool isTerminal;

	// constructor
	trieNode(char data) {
		this -> data = data;
		children = new trieNode*[26];
		isTerminal = false;
	}
};