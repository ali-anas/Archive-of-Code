#include <bits/stdc++.h>
using namespace std;

#define MAX_BIT 31

class trieNode {
	public:
	trieNode* left;
	trieNode* right;
	int nR;
	int nL;
	trieNode() {
		this -> left = NULL;
		this -> right = NULL;
		this -> nR = 0;
		this -> nL = 0;
	}
};

void insert(trieNode* head, int num) {
	trieNode* curr = head;
	for(int i = MAX_BIT; i >= 0; i--) {
		int bit = (num>>i)&1;
        
		if(bit == 0) {
			curr -> nL += 1;
			if(!curr -> left) {
				curr -> left = new trieNode();
			}
            curr = curr -> left;
		}
		else {
			curr -> nR += 1;
			if(!curr -> right) {
				curr -> right = new trieNode();
			}
            curr = curr -> right;
		}
	}
}

long long int find(trieNode* head, int* arr, const int& n, const int& k) {
	insert(head, 0);
 	long long int count = 0;
    int pre_xor = 0;
	for(int i = 0; i < n; i++) {
		pre_xor = pre_xor ^ arr[i];
        
		
        trieNode* curr = head;
		for(int j = MAX_BIT; j >= 0; j--) {
			int subArrBit = (pre_xor>>j)&1;
			int kBit = (k>>j)&1;
			
            if(kBit) {
                if(subArrBit) {
                    count += curr -> nR;
                    curr = curr -> left;
                }
                else {
                    count += curr -> nL;
                    curr = curr -> right;
                }
            }
            else {
                if(subArrBit) {
                    curr = curr -> right;
                }
                else {
                    curr = curr = curr -> left;
                }
            }
			if(curr == NULL) {
				break;
			}
		}
        insert(head, pre_xor);
	}
	return count;
}


int main()
{
    int t;
	cin >> t;
	for(int tc = 1; tc <=t; tc++) {
		int n, k;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		trieNode* head = new trieNode();
		
		long long int ans = find(head, arr, n, k);
		cout << ans << endl;
		delete []arr;
	}
	return 0;
}
