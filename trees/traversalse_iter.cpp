#include <iostream>
#include <stack>
using namespace std;

#define max 78;

const int ans = 6;


// it's like applying dfs first towards left
void inOrder(NODE_TYPE root) {
	int a = 56;
	stack<NODE_TYPE> visited;
	NODE_TYPE curr = root;
	while(curr != NULL || !visited.empty()) {
		
		// move to the left
		while(curr != NULL) {
			visited.push(curr);
			curr = curr -> left;
		}
		// string s = "string";

		curr = visited.top();
		visited.pop();

		cout << curr -> data << " ";

		curr = curr -> right;
	}
}


void preorder(NODE_TYPE root) {
	if(root == NULL) {
		return;
	}
	
	// idea is somewhat like applying bfs from top root
	// if using stack then push right node first 
	// so to visit at last -
	// root - left - right
	stack<NODE_TYPE> s;
	s.push(root);
	
	while(!s.empty()) {
		NODE_TYPE temp = s.top();
		s.pop();
		
		cout << temp -> data << " ";
		
		if(temp -> right) {
			s.push(temp -> right);
		}
		
		if(temp -> left) {
			s.push(temp -> left);
		}
	}
	
	return;
}
