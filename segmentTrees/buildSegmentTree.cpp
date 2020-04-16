#include <bits/stdc++.h>

using namespace std;


#warning "segment tree is stored in array assuming base index 1"

// build a segment tree. O(n)

void buildTree(int* arr, int* tree, int start, int end, int index) {
	if(start == end) {
		tree[index] = arr[start];
		return;
	}
	
	int mid = (start + end) / 2;
	
	buildTree(arr, tree, start, mid, index*2);
	buildTree(arr, tree, mid+1, end, index*2 + 1);
	
	tree[index] = tree[2*index] + tree[2*index+1];
}

void updateTree(int* arr, int* tree, int start, int end, int treeIndex, int index, int value) {
	if(start == end) {
		arr[index] = value;
		tree[treeIndex] = value;
		return;
	}
	
	int mid = (start + end) / 2;
	
	if(index > mid) {
		// go towards right
		updateTree(arr, tree, mid+1, end, (2*treeIndex)+1, index, value);
	} else {
		// go towards left
		updateTree(arr, tree, start, mid, 2*treeIndex, index, value);
	}
	
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

int queryTree(int* tree, int start, int end, int treeIndex, int left, int right) {
	// completely outside of given range.
	if(start > right || end < left) {
		return 0;
	}
	
	// completely inside of given range.
	if(start >= left && end <= right) {
		return tree[treeIndex];
	}
	
	// partially inside/ outside of given range
	int mid = (start + end) / 2;
	int leftAns = queryTree(tree, start, mid, treeIndex*2, left, right);
	int rightAns = queryTree(tree, mid+1, end, treeIndex*2 + 1, left, right);
	
	return leftAns+rightAns;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;
	int* tree = new int[n*2];
	
	buildTree(arr, tree, 0, 4, 1);
	
	updateTree(arr, tree, 0, 4, 1, 2, 10);
	
	for(int i = 1; i < 2*n; i++) {
		printf("%d\n", tree[i]);
	}
	
	int ans = queryTree(tree, 0, 4, 1, 2, 4);
	cout << "ans: " << ans << endl;
	
	delete []tree;
	return 0;
}
