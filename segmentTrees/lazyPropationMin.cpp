#include <bits/stdc++.h>
using namespace std;

// build
void build(int* input, int* tree, int start, int end, int ti) {
	if(start == end) {
		tree[ti] = input[start];
		return;
	}
	
	int mid = (start + end) / 2;
	build(input, tree, start, mid, 2*ti);
	build(input, tree, mid+1, end, 2*ti + 1);
	
	tree[ti] = min(tree[2*ti], tree[2*ti + 1]);
	return;
}

// update range of tree int lazy
void updateLazy(int* tree, int* lazy, int start, int end, int li, int ri, int ti, int value) {
	if(start > end) {
		return;
	}
	
	// update ti if there is some update value int lazy tree.
	// for current ti.
	if(lazy[ti] != 0) {
		tree[ti] += lazy[ti];
		// give update to the children's of current ti.
		if(start != end) {
			lazy[2*ti] += lazy[ti];
			lazy[2*ti+1] += lazy[ti];
		}
		lazy[ti] = 0; // update value of current ti in lazy tree.
	}
	
	// if range does not overlap at all
	if(li > end || ri < start) {
		return;
	}
	
	// if  completely overlap.
	if(start >= li && end <= ri) {
		// update the tree
		tree[ti] += value;
		// tell the child of lazy tree
		if(start != end) {
			lazy[2*ti] += value;
			lazy[2*ti + 1] += value;
		}
		return;
	}
	
	// partial overlap
	
	int mid = (start + end) / 2;
	updateLazy(tree, lazy, start, mid, li, ri, 2* ti, value);
	updateLazy(tree, lazy, mid+1, end, li, ri,2*ti + 1, value);
	
	tree[ti] = min(tree[2*ti], tree[2*ti + 1]);
	return;	
}

// query
int query(int* tree, int* lazy int start, int end, int li, int ri, int ti) {
	// if lies completely outside the given range.
	if(li > end || ri < start) {
		if(lazy[ti] != 0) {
			tree[ti] += lazy[ti];
			//if(start != end) {
			//	tree[2*ti] += lazy[ti];
			//	tree[2*ti+1] += lazy[ti];
			//}
			lazy[ti] = 0;
		}
		return INT_MAX;
	}
	// if lies complpetely inside the range
	if(start >= li && end <= ri) {
		if(lazy[ti] != 0) {
			tree[ti] += lazy[ti];
			lazy[ti] = 0;
		}
		return tree[ti];
	}
		
	// partially inside/outside
	// first check for any updation
	if(lazy[ti] != 0) {
		tree[ti] += lazy[ti];
		// update the children's int lazy tree.
		//if(start != end) {
		//	lazy[2*ti] += lazy[ti];
		//	lazy[2*ti+1] += lazy[ti];
		//}
		lazy[ti] = 0; // update value of current ti in lazy tree.
	}
	
	
	int mid = (start + end) / 2;
	
	int left = query(tree, lazy, start, mid, li, ri, 2*ti);
	int right = query(tree, lazy, mid, end, li, ri, 2*ti+1);
		
	return min(left, right);
}



int main() {
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int* tree = new int[4*n];
	build(input, tree, 0, n-1, 1);
	
	int* lazy = new int[4*n];
	for(int i = 0; i < 4*n; i++) {
		lazy[i] = 0;
	}
	
	cout << "Segment Tree :" << endl;
	updateLazy(tree, lazy, 0, n-1, 0, 3, 1, 3);
	updateLazy(tree, lazy, 0, n-1, 0, 1, 1, 2);
	for(int i = 1; i < 4*n; i++) {
		cout << tree[i] << endl;
	}
	cout << "Lazy Tree :" << endl;
	for(int i = 1; i < 4*n; i++) {
		cout << lazy[i] << endl;
	}
	
	return 0;
}
