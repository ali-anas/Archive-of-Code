#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iipair;

void printVertexPath(const vector<int>& parent, int vertex) {
	stack<int> path;
	while(parent[vertex] != -1) {
		path.push(vertex);
		vertex = parent[vertex];
	}
	cout << vertex ;
	while(!path.empty()){
		cout << " -> " << path.top();
		path.pop();
	}
	return;
}

void printSolution(const vector<int>& distance, const int& n, const vector<int>& parent, const int& source) {
	//int source = 0;
	cout << "Vertex\t\tDistance\t\tPath";
	for(int i = 0; i < n; i++) {
		cout << "\n" << source << " -> " << i << "\t\t" << distance[i] << "\t\t";
		printVertexPath(parent, i);
	}
	cout << "\n";
}

/*
int minDistant(const vector<int>& distance, const vector<bool>& visited, const int &n){
	int min = INT_MAX, min_index;
	for(int i = 0; i < n; i++) {
		if(!visited[i] && distance[i] <= min) {
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

// simple adjacency list - O(V^2)
void printDijkstra(vector<iipair>* edges, const int& n, const int& m, const int& source) {
	vector<int> distance(n, INT_MAX);
	vector<bool> visited(n, false);
	vector<int> parent(n, -1);
	
	distance[source] = 0;
	for(int i = 0; i < n-1; i++) {
		int sourceVertex = minDistant(distance, visited, n);
		visited[sourceVertex] = true;
		
		// update distance of adjacent vertices.
		// if distance through vertex at sIndex is less
		// than previous distance
		for(int i = 0; i < edges[sourceVertex].size(); i++) {
			int destVertex = edges[sourceVertex][i].first;
			int weight = edges[sourceVertex][i].second;
			if(!visited[destVertex] && distance[sourceVertex] + weight < distance[destVertex]) {
				parent[destVertex] = sourceVertex;
				distance[destVertex] = distance[sourceVertex] + weight;
			}
		}
	}
	
	printSolution(distance, n, parent, source); 
}*/

// priority queue O(ElogV)
void printDijkstra(vector<iipair>* edges, const int& n, const int& m, const int& source) {
	priority_queue<iipair, vector<iipair>, greater<iipair> > pq;
	vector<int> parent(n, -1);
	vector<int> distance(n, INT_MAX);
	vector<bool> visited(n, false);
	
	distance[source] = 0;
	pq.push(make_pair(0, source));
	while(!pq.empty()) {
		int sourceVertex = pq.top().second;
		pq.pop();
		visited[sourceVertex] = true;
		for(auto x: edges[sourceVertex]) {
			int destVertex = x.first;
			int weight = x.second;
			if(!visited[destVertex] && distance[destVertex] > distance[sourceVertex] + weight) {
				distance[destVertex] = distance[sourceVertex] + weight;
				pq.push(make_pair(distance[destVertex], destVertex));
				parent[destVertex] = sourceVertex;
			} 
		}
	}
	
	printSolution(distance, n, parent, source);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<iipair>* edges = new vector<iipair>[n];
	for(int i = 0; i < m; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		edges[s].push_back(make_pair(d,w));
		edges[d].push_back(make_pair(s,w));
	}
	
	int source;
	cin >> source;
	printDijkstra(edges, n, m, source);
	return 0;
}
/*
 * graph->
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
5
*/
