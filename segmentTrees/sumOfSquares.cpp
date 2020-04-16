using namespace std;

typedef long long int ll;

struct add {
	ll squaresum;
	ll sum;
};

struct update {
	int type;
	ll value;
};

void build(ll* input, add* tree, int start, int end, int ti) {
	if(start == end) {
		tree[ti].sum = input[start];
		tree[ti].squaresum = input[start] * input[start];
		return;
	}
	
	int mid = (start + end) / 2;
	build(input, tree, start, mid, 2*ti);
	build(input, tree, mid+1, end, 2*ti + 1);
	
	tree[ti].sum = tree[2*ti].sum + tree[2*ti].sum;
	tree[ti].squaresum = tree[2*ti].squaresum + tree[2*ti + 1].squaresum;
	return;
}

void updateLazy1(add* tree, update* lazy, int start, int end, int li, int ri, int ti, int x) {
	if(start > end) {
		return;
	}
	
	// update ti if there is some update value int lazy tree.
	// for current ti. 
	if(lazy[ti].value != 0 && lazy[ti].type == 1) {
		tree[ti].squaresum += 2*tree[ti].sum*lazy[ti].value+ lazy[ti].value*lazy[ti].value*(end - start + 1);
		tree[ti].sum += lazy[ti].value * (end - start + 1);
			
		// give update to the children's of current ti.
		if(start != end) {
			lazy[2*ti].value += lazy[ti].value;
			lazy[2*ti+1].value += lazy[ti].value;
			lazy[2*ti].type = 1;
			lazy[2*ti + 1].type = 1;
		}
		lazy[ti].value = 0; // update value of current ti in lazy tree.
	}
	// if type == 1 add value
	if(lazy[ti].value != 0 && lazy[ti].type == 2) {
		ll data = lazy[ti].value;
		tree[ti].squaresum = (data * data) * (end - start + 1);
		tree[ti].sum = data * (end - start + 1);
		
		// give update to the children's of current ti.
		if(start != end) {
			lazy[2*ti].value += lazy[ti].value;
			lazy[2*ti+1].value += lazy[ti].value;
			lazy[2*ti].type = 2;
			lazy[2*ti+1].type = 2;
		}
			lazy[ti].value = 0; // update value of current ti in lazy tree.
	}
		
	
	// if range does not overlap at all
	if(li > end || ri < start) {
		return;
	}
	
	// if  completely overlap.
	if(start >= li && end <= ri) {
		// update the tree
		tree[ti].squaresum += 2*x*tree[ti].sum + x * x * (end - start + 1);
		tree[ti].sum += x * (end - start + 1);
		
		// tell the child of lazy tree
		if(start != end) {
			lazy[2*ti].value += x;
			lazy[2*ti + 1].value += x;
			lazy[2*ti].type = 1;
			lazy[2*ti + 1].type = 1;
		}
		return;
	}
	
	// partial overlap
	
	int mid = (start + end) / 2;
	updateLazy1(tree, lazy, start, mid, li, ri, 2* ti, x);
	updateLazy1(tree, lazy, mid+1, end, li, ri,2*ti + 1, x);
	
	tree[ti].sum = tree[2*ti].sum + tree[2*ti+1].sum;
	tree[ti].squaresum = tree[2*ti].squaresum + tree[2*ti + 1].squaresum;
	return;	
}





void updateLazy2(add* tree, update* lazy, int start, int end, int li, int ri, int ti, ll x) {
	if(start > end) {
		return;
	}
	
	// update ti if there is some update value int lazy tree.
	// for current ti. 
	if(lazy[ti].value != 0 && lazy[ti].type == 2) {
			tree[ti].squaresum = lazy[ti].value * lazy[ti].value * (end - start + 1);
			tree[ti].sum = lazy[ti].value * (end - start + 1);
			
			// give update to the children's of current ti.
			if(start != end) {
				lazy[2*ti].value += lazy[ti].value;
				lazy[2*ti+1].value += lazy[ti].value;
				lazy[2*ti].type = 2;
				lazy[2*ti + 1].type = 2;
			}
			lazy[ti].value = 0; // update value of current ti in lazy tree.
			lazy[ti].type = 1;
	}
		
	
	// if range does not overlap at all
	if(li > end || ri < start) {
		return;
	}
	
	// if  completely overlap.
	if(start >= li && end <= ri) {
		tree[ti].squaresum += x * x * (end - start + 1);
		tree[ti].sum += x * (end - start + 1);
		
		// tell the child of lazy tree
		if(start != end) {
			lazy[2*ti].value += x;
			lazy[2*ti + 1].value += x;
			lazy[2*ti].type = 2;
			lazy[2*ti + 1].type = 2;
		}
		return;
	}
	
	// partial overlap
	
	int mid = (start + end) / 2;
	updateLazy2(tree, lazy, start, mid, li, ri, 2* ti, x);
	updateLazy2(tree, lazy, mid+1, end, li, ri,2*ti + 1, x);
	
	tree[ti].sum = tree[2*ti].sum + tree[2*ti + 1].sum;
	tree[ti].squaresum = tree[2*ti].squaresum + tree[2*ti + 1].squaresum;
	return;	
}

ll query(add* tree, update* lazy, int start, int end, int ti, int li, int ri) {
	if(start > end) {
		return 0;
	}
	
	// update if there any value at lazy
	if(lazy[ti].value != 0) {
		if(lazy[ti].type == 1) {
			tree[ti].squaresum += 2 * tree[ti].sum * lazy[ti].value + (lazy[ti].value * lazy[ti].value * (end - start + 1));
			tree[ti].sum += (lazy[ti].value * (end - start + 1));
			if(start != end) {
				lazy[2*ti].value += lazy[ti].value;
				lazy[2*ti+1].value += lazy[ti].value;
				lazy[2*ti].type = 1;
				lazy[2*ti + 1].type = 1;
			}
			lazy[ti].value = 0;
		}
		else {
			tree[ti].squaresum = lazy[ti].value * lazy[ti].value * (end - start + 1);
			tree[ti].sum = lazy[ti].value * (end - start + 1);
			
			// give update to the children's of current ti.
			if(start != end) {
				lazy[2*ti].value += lazy[ti].value;
				lazy[2*ti+1].value += lazy[ti].value;
				lazy[2*ti].type = 2;
				lazy[2*ti + 1].type = 2;
			}
			lazy[ti].value = 0; // update value of current ti in lazy tree.
			lazy[ti].type = 1;
		}
	}

	// no overlap
	if(li > end || ri < start) {
		return 0;
	}
	
	// completely overlap
	if(start >= li && end <= ri) {
		return tree[ti].squaresum;
	}
	
	// overlap partially
	int mid = (end + start) / 2;
	
	ll left = query(tree, lazy, start, mid, 2*ti, li, ri);
	ll right = query(tree, lazy, mid+1, end, 2*ti+1, li, ri);
	
	return left+right;
}

int main() {

	// Write your code here
    int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		int n, q;
		cin >> n >> q;
		ll* input = new ll[n];
		for(int i = 0; i < n; i++) {
			cin >> input[i];
		}
		
		
		add* tree = new add[4*n];
		build(input, tree, 0, n-1, 1);
		
		update* lazy = new update[4*n];
		// for(int i = 0; i < n; i++) {
		// 	lazy[i].value = 0;
		// }
		cout << "Case " << tc << ":" << endl;
		for(int i = 1; i <= q; i++) {
			int option;
			cin >> option;
			if(option == 2) {
				int st, nd;
				cin >> st >> nd;
				ll ans = query(tree, lazy, 0, n-1, 1, st-1, nd-1);
				cout << ans << endl;
			}
			if(option == 1) {
				int st, nd;
                ll x;
				cin >> st >> nd >> x;
				updateLazy1(tree, lazy, 0, n-1, st-1, nd-1, 1, x);
			}
			if(option == 0) {
				int st, nd;
                ll x;
				cin >> st >> nd >> x;
				updateLazy2(tree, lazy, 0, n-1, st-1, nd-1, 1, x);
			}	
		}
	}
	return 0;
}
