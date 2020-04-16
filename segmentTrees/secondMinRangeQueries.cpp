#include <bits/stdc++.h>
using namespace std;

struct node {
	int maximum;
	int smaximum;
};

void buildTree(int* input, node* tree, int start, int end, int treeIndex) {
	if(start == end) {
		tree[treeIndex].maximum = input[start];
		tree[treeIndex].smaximum = INT_MIN;
		return;
	}
		
	
	int mid = (start + end) / 2;
	buildTree(input, tree, start, mid, 2*treeIndex);
	buildTree(input, tree, mid+1, end, 2*treeIndex +1);
	
	struct node left = tree[2*treeIndex];
	struct node right = tree[2* treeIndex + 1];
	int maxVal = max(left.maximum, right.maximum);
	int minVal = min(max(right.smaximum, left.maximum), max(right.maximum, left.smaximum));
	
	tree[treeIndex].smaximum = minVal;
	tree[treeIndex].maximum = maxVal;
	return;
}


void updateTree(int* input,	node* tree, int start, int end, int treeIndex, 
				int value, int index) {
	if(start == end) {
		input[index] = value;
		tree[treeIndex].maximum = value;
		tree[treeIndex].smaximum = INT_MIN;
		return;
	}
	
	int mid = (start + end) / 2;
	if(index > mid) {
		updateTree(input, tree, mid+1, end, 2*treeIndex + 1, value, index);
	} else {
		updateTree(input, tree, start, mid, 2*treeIndex, value, index);
	}
	
	node left = tree[2*treeIndex];
	node right = tree[2* treeIndex + 1];
	int maxVal = max(left.maximum, right.maximum);
	int minVal = min(max(right.smaximum, left.maximum), max(right.maximum, left.smaximum));
	
	tree[treeIndex].smaximum = minVal;
	tree[treeIndex].maximum = maxVal;
	return;
}

node query(node* tree, int start, int end, int left, int right, int treeIndex) {
	// completely outside of range
	if(start > right || end < left) {
		node zero;
		zero.maximum = INT_MIN;
		zero.smaximum = INT_MIN;
		return zero;
	}
	
	// completely inside the range
	if(start >=  left && end <= right) {
		 	return tree[treeIndex];
	}
	
	// partially inside/ outside the range.
	int mid = (start + end) / 2;
	
	node leftAns = query(tree, start, mid, left, right, 2*treeIndex);	
	node rightAns = query(tree, mid+1, end, left, right, 2*treeIndex + 1);
	
	node ans;
	ans.maximum = max(leftAns.maximum, rightAns.maximum);
	ans.smaximum = min(max(leftAns.maximum, rightAns.smaximum), max(rightAns.maximum, leftAns.smaximum));
	return ans;
}

int main() {
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	node* tree = new node[3*n];
	buildTree(input, tree, 0, n-1, 1);
	
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		char option;
		scanf(" %c", &option);
		if(option == 'Q') {
			int left, right;
			scanf("%d%d", &left, &right);
			node ans = query(tree, 0, n-1, left-1, right-1, 1);
			printf("%d\n", ans.maximum+ans.smaximum);
			continue;
		}
		if(option == 'U') {
			int index, value;
			scanf("%d%d", &index, &value);
			updateTree(input, tree, 0, n-1, 1, value, index-1);
		}
	}

	return 0;
}	
