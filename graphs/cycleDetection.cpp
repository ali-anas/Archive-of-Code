#include <bits/stdc++.h>
using namespace std;

// UNION FIND PATH COMPRESSION
const int MAX_VERTEX = 101;
// parent of index i
int parent[MAX_VERTEX];

// to represent the number of nodes
// in a subgraph rooted at index at i
int size[MAX_VERTEX];

// set parent of every nodes &
// size of node to one
void initialize(int n) {
	for(int i = 0; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	return;
}

// each time we follow a path, find function
// compresses it further until the path length
// is greater than or equal to 1.
// FIND
int getParent(int i) {
	while(parent[i] != i) {
		parent[i] = parent[parent[i]]; // skip one level. PATH COMPRESSION
		i = parent[i];
	}
	return i;
}

// UNION
void _union(int sourceParent, int destParent) {
	if(size[sourceParent] < size[destParent]) {
		// make parent of destParent also the
		// the parent of sourceParent
		parent[sourceParent] = parent[destParent];
		size[destParent] += size[sourceParent];
	}
	else {
		// make sourceParent parent of destParent
		parent[destParent] = parent[sourceParent];
		size[sourceParent] += size[destParent];
	}
}

// to check whether a graph contains cycle or not
bool isCycle(vector<int>* adj, int n) {
	// iterate through all edges of graph, & find
	// node connecting them.
	// if root nodes of both of them are same, then
	// there is a cycle in graph.
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < adj[i].size(); j++) {
			int sParent = getParent(i);
			int dParent = getParent(adj[i][j]);
			
			if(sParent == dParent) {
				//cout <<"vert" << i <<" " << adj[i][j] << endl;
				return true;
			}
			_union(sParent, dParent);
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	initialize(n);
	vector<int>* adj = new vector<int>[n];
	for(int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		adj[s].push_back(d);
		//adj[d].push_back(s);
	}
	
	if(isCycle(adj, n)) {
		cout << "Graph contains cycle.\n";
	} else {
		cout << "Graph does not contain cycle\n";
	}
	return 0;
}
