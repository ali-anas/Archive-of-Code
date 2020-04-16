#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 1;
int power[MAX];

void giveNo() {
	power[0] = 1;
	for(int i = 1; i < MAX; i++) 
		power[i] = (power[i-1]*2) % 3;
}

void build(int* tree, int* input, int start, int end, int ti) {
	if(start == end) {
		tree[ti] = input[start];
		return;
	}
		int mid = (start + end) / 2;
		build(tree, input, start, mid, 2*ti);
		build(tree, input, mid+1, end, 2*ti+1);
		
		tree[ti] = (power[end-mid] * tree[2*ti] + tree[2*ti + 1]) % 3;
}

int query(int* tree, int start, int end, int ti, int li, int ri) {
	if(start > ri || end < li) {
		return 0;
	}
	if(start >= li && end <= ri) {
		return (tree[ti]*power[ri - end]) % 3;
	}
	
	int mid = (start + end) / 2;
	int left = query(tree, start, mid, 2*ti, li, ri);
	int right = query(tree, mid+1, end, 2*ti+1, li, ri);
	return (left+right) % 3;
}

void update(int* tree, int* input, int start, int end, int ti, int key) {
	if(start == end) {
		input[key] = 1;
		tree[ti] = 1;
		return;
	}
	
	int mid = (start + end) / 2;
	if(key >= start && mid >= key) {
		update(tree, input, start, mid, 2*ti, key);
	} else {
		update(tree, input, mid+1, end, 2*ti+1, key);
	}
	
	tree[ti] = (power[end - mid] * tree[2*ti] + tree[2*ti+1]) % 3;
	return;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int* input = new int[n];
	for(int i = 0; i < n; i++) {
		input[i] = s[i] - '0';
	}
	
	giveNo();
	int* tree = new int[4*n];
	build(tree, input, 0, n-1, 1);
	
	int q, type, li, ri;
	cin >> q;
	while(q--) {
		cin >> type;
		if(type == 0) {
			cin >> li >> ri;
			cout << query(tree, 0, n-1, 1, li, ri);
		}
		else {
			cin >> key;
			if(intput[key] == 0)
				update(tree, input, 0, n-1, 1, key);
		}
	}
	delete []input;
	delete []tree;
	return 0;
}
