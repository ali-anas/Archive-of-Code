#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iipair;

void shortestPath(vector<iipair>* edges, int n, int source) {
	priority_queue<iipair, vector<iipair> , greater<iipair> > pq;
	vector<int> distance(n, INF);
	
	vector<bool> visited(n, false);
	
	pq.push(make_pair(0, source));
	distance[0] = 0;
	
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
			}
		}
	}
	
	cout << "Vertex		Distance from source\n";
	for(int i = 0; i < n; i++) {
		cout << i << "\t\t" << distance[i] << "\n";
	} 
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
	
	shortestPath(edges, n, 0);
	
	delete []edges;
	
	return 0;
}
