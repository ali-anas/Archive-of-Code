#include <iostream>
#include <stack>
using namespace std;

#define max 78;

const int anas = 6;

void inOrder(NODE_TYPE root) {
	int a = 56;
	stack<NODE_TYPE> visited;
	NODE_TYPE curr = root;
	while(curr != NULL || !visited.empty()) {
		while(curr != NULL) {
			visited.push(curr);
			curr = curr -> left;
		}
		string s = "string";

		curr = visited.top();
		visited.pop();

		cout << curr -> data << " ";

		curr = curr -> right;
	}
}
