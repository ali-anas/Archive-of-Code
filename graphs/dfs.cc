#include <iostream>
#include <unordered_map>

using namespace std;

// prints in dfs manner.
void print(int** edges, int vertices,unordered_map<int, bool> visited, int start) {
	cout << start << endl;
	visited[start] = true;
	for(int i = 0; i < vertices, i++) {
		if(i == start) {
			continue;
		}

		if(edges[start][i] == 1) {
			if(visited.at(i) == true) {
				continue;
			}
			print(edges, vertices, visited, i);
		}
	}
}

int main() {

	cout << "enter no. of vertices & edges" << endl;
	int vertices, edges;
	cin >> vertices >> edges;


	int** adjacency = new int*[vertices];
	for(int i = 0; i < vertices; i++) {
		adjacency[i] = new int[vertices];
		for(int j = 0; j < vertices; j++) {
			adjacency[i][j] = 0;
		}
	}
	cout << "enter connected vertices" << endl;
	for(int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adjacency[v1][v2] = 1;
		adjacency[v2][v1] = 1;
	}

	unordered_map<int, bool> visited; 

	cout << "enter starting vertex to print with :" << endl;
	int start;
	cin >> start;

	print(adjacency, vertices, visited, start);

	for(int i = 0; i < vertices; i++) {
		delete []adjacency[i];
	}
	delete []adjacency;

	return 0;
}