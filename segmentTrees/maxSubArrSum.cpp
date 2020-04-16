#include <bits/stdc++.h>

using namespace std;
struct node {
	int msum;	// maximum sum
	int sum;	// total sum
	int bps;	// best prefix sum
	int bss;	// best suffix sum
};

void buildTree(int* input, node* tree, int start, int end, int treeIndex) {
	if(start == end) {
		tree[treeIndex].msum= input[start];
		tree[treeIndex].sum = input[start];
		tree[treeIndex].bps = input[start];
		tree[treeIndex].bss = input[start];
		return;
	}
	
	int mid = (start + end) / 2;
	buildTree(input, tree, start, mid, 2*treeIndex);
	buildTree(input, tree, mid+1, end, 2*treeIndex+1);
	
	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];
	
	tree[treeIndex].sum = left.sum + right.sum;
	tree[treeIndex].bps = max(left.bps, left.sum + right.bps);
	tree[treeIndex].bss = max(right.bss, right.sum + left.bss);
	tree[treeIndex].msum = max(left.msum, max(right.msum, max(left.sum + right.bps, max(right.sum + left.bss, left.bss + right.bps))));
	return;
}

node query(node* tree, int start, int end, int lr, int rr, int treeIndex) {
	// totaly outside.
	if(lr > end || rr < start) {
		node zero;
		zero.msum = INT_MIN;
		zero.sum = INT_MIN;
		zero.bps = INT_MIN;
		zero.bss = INT_MIN;
		return zero;
	}
	
	// totaly inside
	if(start >= lr && end <= rr) {
		return tree[treeIndex];
	}
	
	// partially inside/outside
	int mid = (start + end) / 2;
	node left = query(tree, start, mid, lr, rr, 2*treeIndex);
	node right = query(tree, mid+1, end, lr, rr, 2*treeIndex+1);
	
	node ans;
	ans.sum = left.sum + right.sum;
	ans.bps = max(left.bps, left.sum + right.bps);
	ans.bss = max(right.bss, right.sum + left.bss);
	ans.msum = max(left.msum, max(right.msum, max(left.sum + right.bps, max(right.sum + left.bss, left.bss + right.bps))));
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
	
	int m;
	cin >> m;
	for(int i = 1; i <=m; i++) {
		int lr, rr;
		cin >> lr >> rr;
		node ans = query(tree, 0, n-1, lr-1, rr-1, 1);
		cout << ans.msum << endl;
	}
	
	delete []input;
	delete []tree;
	return 0;
}
