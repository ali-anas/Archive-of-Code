#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int source;
	int dest;
	int weight;
};

bool compare(Edge val1, Edge val2) {
	return val1.weight < val2.weight;
}

int getParent(int* parent, const int& vertex) {
	if(parent[vertex] == vertex) {
		return vertex;
	}
	return getParent(parent, parent[vertex]);
}

pair<int, int> getAnsKruskal(Edge* input, const int& noVert, const int& noEdges, const int& acost) {
	sort(input, input + noEdges, compare);
	
	int* parent = new int[noVert];
	for(int i = 0; i < noVert; i++) {
		parent[i] = i;
	}
	
	int total = 0;
	
	for(int i = 0; i < noEdges; i++) {
		Edge e = input[i];
		
		int pSource = getParent(parent, e.source);
		int pDest = getParent(parent, e.dest);
		
		if(pSource != pDest && e.weight < acost) {
			total += e.weight;
			parent[pDest] = pSource;
		}
	}
	
	int noOfAirport = 0;
	for(int i = 0; i < noVert; i++) {
		if(parent[i] == i) {
			total += acost;
			noOfAirport++;
		}
	}
	delete []parent;
	return make_pair(total, noOfAirport);
}

int main() {
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		int n, m, acost;
		cin >> n >> m >> acost;
		Edge* input = new Edge[m];
		for(int i = 0; i < m; i++) {
			int s, d, w;
			cin >> s >> d >> w;
			input[i].source = s-1;
			input[i].dest = d-1;
			input[i].weight = w;
		}
		
		pair<int, int> output = getAnsKruskal(input, n, m, acost);
		cout << "Case #" << tc << ": " << output.first << " " << output.second << "\n";
		delete []input;
	}
	return 0;
}
