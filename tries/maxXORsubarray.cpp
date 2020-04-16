#include<bits/stdc++.h>
using namespace std;

class trieNode {
public:
	trieNode* left;
	trieNode* right;
	
	trieNode() {
		this -> left = NULL;
		this -> right = NULL;
	}
};

void insert(trieNode* head, int num) {
	trieNode* curr = head;
	for(int i = 31; i >= 0; i--) {
		int bit = (num>>i)&1;
		if(bit == 0) {
			if(!curr -> left) {
				curr -> left = new trieNode();
			}
			curr = curr -> left;
		}
		else {
			if(!curr -> right) {
				curr -> right = new trieNode();
			}
			curr = curr -> right;
		}
	}
}

int find(int* input, int n, trieNode* head) {
	insert(head, 0);
	int over_all_max = INT_MIN;
	int prev_xor = 0;
	
	for(int i = 0; i < n; i++) {
		prev_xor = prev_xor ^ input[i];
		insert(head, prev_xor);
		
		trieNode* curr = head;
		int curr_xor = 0;
		for(int j = 31; j >= 0; j--) {
			int bit = (prev_xor>>j)&1;
			
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
		over_all_max = max(over_all_max, curr_xor);
	}
	return over_all_max;
}


int main() {
    int n;
	cin >> n;
	int* input = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	trieNode* head = new trieNode();
	int ans = find(input, n, head);
    cout << ans << endl;
	return 0;
}
