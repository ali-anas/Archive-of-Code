#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int source;
	int dest;
};

struct Subset {
	int parent;
	int rank;
};

int find(struct Subset* sub, int vertex) {
	/* // iterative
	 * while(sub[vertex].parent != vertex) {
	 * 		sub[vertex].parent = sub[sub[vertex].parent].parent;
	 * 		vertex = sub[vertex].parent;
	 * }
	 * return vertex;
	 */
	if(sub[vertex].parent != vertex)
		sub[vertex].parent = find(sub, sub[vertex].parent);
	
	return sub[vertex].parent;
}

void Union(struct Subset* sub, int sParent, int dParent) {
	int sourceParent = find(sub, sParent);
	int destParent = find(sub, dParent);
	
	// attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if(sub[sourceParent].rank < sub[destParent].rank) {
		sub[sourceParent].parent = destParent;
	} 
	else if(sub[sourceParent].rank > sub[destParent].rank) {
		sub[destParent].parent = sourceParent;
	} 
	else {
		sub[destParent].parent = sourceParent;
		sub[sourceParent].rank++;
	}
}

bool isCycle(Edge* edges, const int &n, const int &m) {
	// create subset
	Subset* sub = new Subset[n];
	for(int i = 0; i < n; ++i) {
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	
	// iterate through all edges and find parents
	// of both vertices of edge, if both are in same set 
	// then there is cycle
	for(int i = 0; i < m; i++) {
		int sParent = find(sub, edges[i].source);
		int dParent = find(sub, edges[i].dest);
		
		if(sParent == dParent) {
			return true;
		}
		Union(sub, sParent, dParent);
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	Edge* edges = new Edge[m];
	for(int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		edges[i].source = s;
		edges[i].dest = d;
	}
	
	if(isCycle(edges, n, m)) {
		printf("Graph contains cycle\n");
	} else {
		printf("Graph does not contain cycle\n");
	}
	return 0;
}
