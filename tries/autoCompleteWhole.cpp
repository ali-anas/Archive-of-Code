#include <bits/stdc++.h>
using namespace std;

class trieNode {
    public:
    trieNode **children;
    bool isTerminal;
    char data;
    trieNode(char data) {
        this -> data = data;
        this -> isTerminal = false;
        children = new trieNode*[26];
    }
};

class trie {
    private:
    trieNode* root = NULL;

    void insertHelper(trieNode* root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        trieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new trieNode(word[0]);
            root -> children[index] = child;
        }
        insertHelper(child, word.substr(1));
        return;
    }

    public:
    trie() {
        root = new trieNode('\0');
    }

    void insert(string& word) {
        insertHelper(this -> root, word);
        return;
    }

    void autoComplete(string& suffix);
};

void printSuggestions(trieNode* root, string seen) {
    if(root -> isTerminal) {
        cout << seen << "\n";
    }

    for(int i = 0; i < 26; i++) {
        if(root -> children[i] != NULL) {
            char nextChar = root -> children[i] -> data;
            printSuggestions(root->children[i], seen+nextChar);
        }
    }
    return;
}

bool checkIfSuffixExists(trieNode* root, string suffix, string seen) {
    if(suffix.size() == 0) {
        printSuggestions(root, seen);
        return true;
    }

    int index = suffix[0]-'a';
    trieNode* child;
    if(root -> children[index] != NULL) {
        child = root -> children[index];
        return checkIfSuffixExists(child, suffix.substr(1), seen+suffix[0]);
    }
    return false;
}

void trie :: autoComplete(string& suffix) {
    string seen = "";
    if(!checkIfSuffixExists(this -> root, suffix, seen)) {
        insert(suffix);
        cout << "No suggestions\n";
    }

}


int main() {
    int n, q;
    cin >> n;
    trie* t = new trie();
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        t->insert(input);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;
        t->autoComplete(s);
    }

    delete t;
    return 0;
}