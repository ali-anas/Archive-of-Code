#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1e6 + 5;
int a[MAX_N];
int tree[4*MAX_N];

void buildSegmentTree(int start, int end, int index) {
	if(start == end) {
		tree[index] = a[start];
		return;
	}
	
	int mid = (start + end) / 2;
	buildSegmentTree(start, mid, 2*index);
	buildSegmentTree(mid+1, end, 2*index + 1);
	
	tree[index] = min(tree[2*index], tree[2*index + 1]);
}

void updateTree(int start, int end, int treeIndex, int index, int value) {
	if(start == end) {
		a[index] = value;
		tree[treeIndex] = value;
		return;
	}
	
	int mid = (start + end) / 2;
	if(index > mid) {
		updateTree(mid+1, end, treeIndex*2 + 1, index, value);
	} else {
		updateTree(start, mid, treeIndex*2, index, value);
	}
	
	tree[treeIndex] = min(tree[treeIndex*2], tree[treeIndex*2 + 1]);
}

int queryTree(int start, int end, int left, int right, int treeIndex) {
	// completely outside of range
	if(start > right || end < left) {
		return 0;
	}
	
	// completely inside the range
	if(start >= left && end <= right) {
		return tree[treeIndex];
	}
	
	// partially inside/outside
	int mid = (start + end) / 2;
	int leftAns = queryTree(start, mid, left, right, treeIndex*2);
	int rightAns = queryTree(mid+1, end, left, right, treeIndex*2 + 1);
	
	return min(leftAns, rightAns);
}

int main() {
	int n, Q;
	scanf("%d%d", &n, &Q);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	buildSegmentTree(0, n-1, 1);
	
	for(int t = 0; t < Q; t++) {
		char option; // can be either 'q' or 'u'
		scanf(" %c", &option);
		if(option == 'q') {
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = queryTree(0, n-1, l-1, r-1, 1);
			printf("%d\n", ans);	
		} 
		if(option == 'u') {
			int index, value;
			scanf("%d%d", &index, &value);
			updateTree(0, n-1, 1, index-1, value);
		}
	}
	
	return 0;
}
