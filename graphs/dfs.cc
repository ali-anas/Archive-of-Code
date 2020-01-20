#include <iostream>
using namespace std;


void print(int** edges, int vertices, bool* visited, int start) {
	cout << start << endl;
	visited[start] = true;
	for(int i = 0; i < vertices, i++) {
		if(i == start) {
			continue;
		}

		if(edges[start][i] == 1) {
			if(visited[i]) {
				continue;
			}
			print(edges, vertices, visited, i);
		}
	}
}

int main(int argc, char[]* argv) {
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
	for(int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adjacency[v1][v2] = 1;
		adjacency[v2][v1] = 1;
	}

	bool* visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	cout << "enter starting vertex to print" << endl;
	int start;

	print(adjacency, vertices, visited, start);

	for(int i = 0; i < vertices; i++) {
		delete []adjacency[i];
	}
	delete []adjacency;

	delete []visited;

	return 0;

}