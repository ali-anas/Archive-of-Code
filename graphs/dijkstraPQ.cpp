#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph {
	int n;
	list<pair<int, int> > *adj;
public:
	Graph(int n);
	void addEdge(int source, int dest, int weight);
	void shortestPath(int source);
};

Graph :: Graph(int n) {
	this -> n = n;
	adj = new list<pair<int, int> >[n];
	return;
}

void Graph :: addEdge(int source, int dest, int weight) {
	adj[source].push_back(make_pair(dest, weight));
	adj[dest].push_back(make_pair(source, weight));
	return;
}

void Graph :: shortestPath(int source) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> distance(n, INF);
	
	pq.push(make_pair(0, source));
	distance[source] = 0;
	
	while(!pq.empty()) {
		int sourceVertex = pq.top().second;
		pq.pop();
		
		list<pair<int, int> >::iterator it = adj[sourceVertex].begin();
		for( ; it != adj[sourceVertex].end(); ++it) {
			int destVertex = (*it).first;
			int weight = (*it).second;
			
			if(distance[destVertex] > distance[sourceVertex] + weight) {
				distance[destVertex] = distance[sourceVertex] + weight;
				pq.push(make_pair(distance[destVertex], destVertex));
			}
		}
	}
	
	printf("Vertex	Distance from source\n");
	for(int i = 0; i < n; i++) {
		printf("%d \t\t %d\n", i, distance[i]);
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	
	for(int i = 0; i < m; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		g.addEdge(s, d, w);
	}
	
	g.shortestPath(0);
	return 0;
}
