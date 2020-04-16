#include <bits/stdc++.h>
using namespace std;


struct node {
	int evencount = 0;
	int oddcount = 0;
};

void build(int* input, node* tree, int start, int end, int ti) {
	if(start == end) {
		tree[ti].evencount = tree[ti].oddcount = 0;
		if(input[start]&1) {
			tree[ti].oddcount++;
		} else {
			tree[ti].evencount++;
		}
		return;
	}
	
	int mid = (start + end) / 2;
	build(input, tree, start, mid, 2*ti);
	build(input, tree, mid+1, end, 2*ti + 1);
	
	tree[ti].evencount = tree[2*ti].evencount + tree[2*ti + 1].evencount;
	tree[ti].oddcount = tree[2*ti].oddcount + tree[2*ti + 1].oddcount;
	return;
}

void update(int* input, node* tree, int start, int end, int ti, int index, int value) {
	if(start == end) {
		int temp = input[index];
		//(temp&1) ? tree[ti].oddcount-- : tree[ti].evencount--;
		input[index] = value;
		if((value&1) && !(temp&1)) {
			tree[ti].oddcount++;
			tree[ti].evencount--;
		} else if(!(value&1) && (temp&1)) {
			tree[ti].evencount++;
			tree[ti].oddcount--;
		}
		//cout << tree[ti].evencount << " " << tree[ti].oddcount <<endl;
		return;
	}
	
	int mid = (start + end) / 2;
	if(index > mid) {
		update(input, tree, mid+1, end, 2*ti + 1, index, value);
	} else {
		update(input, tree, start, mid, 2*ti, index, value);
	}
	
	tree[ti].evencount = tree[2*ti].evencount + tree[2*ti + 1].evencount;
	tree[ti].oddcount = tree[2*ti].oddcount + tree[2*ti + 1].oddcount;
	return;
}

node query(node* tree, int start, int end, int li, int ri, int ti) {
	// range is completely outside
	if(li > end || ri < start) {
		// #warning apply appropriate values
		node ans;
		ans.oddcount = 0;
		ans.evencount = 0;
		return ans;
	}
	
	// range is completely inside
	if(start >= li && end <= ri) {
		return tree[ti];
	}
	
	// range is partially inside/outside
	int mid = (start + end) / 2;
	node left = query(tree, start, mid, li, ri, 2*ti);
	node right = query(tree, mid+1, end, li, ri, 2*ti + 1);
	
	node ans;
	ans.oddcount = left.oddcount + right.oddcount;
	ans.evencount = left.evencount + right.evencount;
	return ans;
}


int main() {
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	node* tree = new node[4*n];
	build(input, tree, 0, n-1, 1);
	/*
	for(int i = 1; i < 4*n; i++) {
		cout << tree[i].evencount << " " << tree[i].oddcount << endl;
	}*/
	
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int option, l, r;
		cin >> option >> l >> r;
		if(option == 0) {
			update(input, tree, 0, n-1, 1, l-1, r);
		}
		if(option == 1 || option == 2) {
			node ans = query(tree, 0, n-1, l-1, r-1, 1);
			if(option&1) {
				cout << ans.evencount << endl;
			}
			else {
				cout << ans.oddcount << endl;
			}
		}
	}
	
	delete []input;
	delete []tree;
	
	return 0;
			
	
}
