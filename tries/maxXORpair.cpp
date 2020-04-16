#include <bits/stdc++.h>
using namespace std;

class trieNode {
	public:
	trieNode *left;		// 0
	trieNode* right;	// 1
};

// use 32 bits concept -> 31, 30, 29, .... 1, 0
void insert(int n, trieNode* head) {
	trieNode* curr = head;
	for(int i = 31; i >= 0; i--) {
		int bit = (n>>i)&1;		// left shift n with i
		
		if(bit == 0) {
			if(!curr -> left) {
				curr -> left = new trieNode();
			}
			curr = curr -> left;
		} else {
			if(!curr -> right) {
				curr -> right = new trieNode();
			}
			curr = curr -> right;
		}
	}
}

int findMaxXORpair(trieNode* head, int* arr, int n) {
	int max_xor = INT_MIN;
	for(int i = 0; i < n; i++) {
		trieNode* curr = head;
		int curr_xor = 0;
		int value = arr[i];
		for(int j = 31; j >= 0; j--) {
			int bit = (value>>j)&1;
			if(bit == 0) {
				if(curr -> right) {
					curr = curr -> right;
					curr_xor += pow(2,j);
				}
				else {
					curr = curr -> left;
				}
			} 
			else {
				if(curr -> left) {
					curr = curr -> left;
					curr_xor += pow(2,j);
				}
				else {
					curr = curr -> right;
				}
			}
		}
		if(curr_xor > max_xor) {
			max_xor = curr_xor;
		}
	}
	
	return max_xor;
}


int main() {
	int arr[6] = {8, 1, 2, 15, 10, 5};
	trieNode* head = new trieNode();
	for(int i = 0 ; i < 6; i++) {
		insert(arr[i], head);
	}
	
	cout << findMaxXORpair(head, arr, 6) << endl;
}
