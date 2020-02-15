#include <iostream>
#include <climits>

using namespace std;

int findMinVertex(int* weight, bool* visited, const int &v) {
	int ans = -1;
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (ans == -1 || weight[i] < weight[ans])) {
			ans = i;
		}
	}
	return ans;
}

void prims(int** adj, const int &v) {
	int* parent = new int[v];
	int* weight = new int[v];
	bool* visited = new bool[v];

	for(int i = 0; i < v; i++) {
		visited[i] = false;
		weight[i] = INT_MAX;
	}

	parent[0] = -1;
	weight[0] = 0;

	for(int i = 0; i < v; i++) {
		int vertex = findMinVertex(weight, visited, v);
		visited[vertex] = true;
		for(int j = 0; j < n; j++) {
			if(!visited[j] && adj[vertex][j] != 0) {
				if(adj[vertex][j] < weight[j]) {
					weight[j] = adj[vertex][j];
					parent[j] = vertex;
				}
			}
		}
	}

	for(int i = 1; i < v; i++) {
		if(parent[i] < i) {
			cout << parent[i] << i << weight[i] << endl;
		} else {
			cout << i << parent[i] << weight[i] << endl;
		}
	}

	delete []visited;
	delete []parent;
	delete []weight;
}

int main() {
	int v, e;
	cin >> v >> e;
	int** adj = new int*[v];
	for(int i = 0; i< v; i++) {
		adj[i] = new int[v];
		for(int j = 0; j < v; j++) {
			adj[i][j] = 0;
		}
	}

	for(int i = 0; i < e; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		adj[s][d] = w;
		adj[d][s] = w;
	}

	prims(adj, v);

	for(int i = 0; i < v; i++) {
		delete []adj[i];
	}
	delete []adj;

	return 0;
}