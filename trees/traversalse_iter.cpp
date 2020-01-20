#include <iostream>
#include <stack>

void inOrder(NODE_TYPE root) {
	stack<NODE_TYPE> visited;
	NODE_TYPE curr = root;
	while(curr != NULL || !visited.empty()) {
		while(curr != NULL) {
			visited.push(curr);
			curr = curr -> left;
		}

		curr = visited.top();
		visited.pop();

		cout << curr -> data << " ";

		curr = curr -> right;
	}
}