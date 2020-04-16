#include <bits/stdc++.h>
using namespace std;

class trieNode {
    public:
    char data;
    trieNode** children;
    bool isTerminal;
    int maxWeight;
    trieNode(char data) {
        this -> data = data;
        children = new trieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        maxWeight = INT_MIN;
    }
};

class trie {
    public:
    trieNode *root = NULL;

    trie() {
        root = new trieNode('\0');
    }
    void insert(trieNode* root, string word, int weight);
    int getMaxWeightSuggestion(trieNode* root, string word);

};

void trie::insert(trieNode* root, string word, int weight) {
    if(word.size() == 0) {
        root -> isTerminal = true;
        return;
    }

    int index = word[0] - 'a';
    trieNode* child;
    if(root -> children[index] != NULL) {
        child = root -> children[index];
    } else {
        child = new trieNode(word[0]);
        root -> children[index] = child;
    }
    child -> maxWeight = max(child->maxWeight, weight);
    insert(child, word.substr(1), weight);
}

int trie::getMaxWeightSuggestion(trieNode* root, string word) {
    // #warning return integer type
    if(word.size() == 0) {
        return root -> maxWeight;
    }
    int index = word[0] - 'a';
    if(root -> children[index] == NULL) {
        return -1;
    }
    else {
        trieNode* child = root -> children[index];
        return getMaxWeightSuggestion(child, word.substr(1));
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    trie* t = new trie();
    for(int i = 0; i < n; i++) {
        string input;
        int weight;
        cin >> input;
        cin >> weight;
        t->insert(t -> root, input, weight);
    }

    for(int i = 0; i < q; i++) {
        string toSearch;
        cin >> toSearch;
        int myOutput = t->getMaxWeightSuggestion(t -> root, toSearch);
        cout << myOutput << endl;
    }
    
    delete t;
    return 0;
}