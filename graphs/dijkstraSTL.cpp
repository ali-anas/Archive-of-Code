/*
 * 1) Initialize distances of all vertices as infinite.
	2) Create an empty set.  Every item of set is a pair
	(weight, vertex). Weight (or distance) is used used
	as first item  of pair as first item is by default 
	used to compare two pairs.

	3) Insert source vertex into the set and make its
	distance as 0.

	4) While Set doesn't become empty, do following
		a) Extract minimum distance vertex from Set. 
		Let the extracted vertex be u.
		b) Loop through all adjacent of u and do 
			following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (i) If v is in set, update its distance
                   in set by removing it first, then
                   inserting with new distance
               (ii) If v is not in set, then insert
                    it in set with new distance
               
	5) Print distance array dist[] to print all shortest
		paths.
	*/ 


#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph {
	int n; // no of vertices
	
	// pair of dest and weight
	// for each edge in weighted graph.
	list<pair<int, int> > *adj;
public:
	Graph(int n);	// constructor
	// function to add edge to graph
	void addEdge(int source, int dest, int weight);
	
	// print shortest path from source
	void shortestPath(int source);
};

Graph :: Graph(int n) {
	this -> n = n;
	adj = new list<pair<int, int> >[n];
}

void Graph :: addEdge(int source, int dest , int weight) {
	adj[source].push_back(make_pair(dest, weight));
	adj[dest].push_back(make_pair(source, weight));
}

void Graph :: shortestPath(int source) {
	// set of vertices that are preprocessed.
	// pair -> <weight, vertex>
	// because by default set compares with first first value.
	set< pair<int, int> > setds;
	
	// distance vector
	vector<int> distance(n, INF);
	
	// insert source vertex in set and
	// initialize distance 0.
	setds.insert(make_pair(0, source));
	distance[source] = 0;
	
	while(!setds.empty()) {
		// first vertex in set is minimum distance
		// vertex. sorted based on weight
		// set is implemented using self-balancing BST.
		pair<int, int> temp = *(setds.begin());
		setds.erase(setds.begin());
		
		// get vertex
		int sourceVertex = temp.second;
		
		// get all adjacent vertices of sourceVertex
		list<pair<int, int> >::iterator it = adj[sourceVertex].begin();
		for( ; it != adj[sourceVertex].end(); it++) {
			// get neighbour and its weight from source
			int neighbour = (*it).first;
			int weight = (*it).second;
			
			if(distance[neighbour] > distance[sourceVertex] + weight) {
				if(distance[neighbour] != INF) {
					setds.erase(setds.find(make_pair(distance[neighbour], neighbour)));
				}
				distance[neighbour] = distance[sourceVertex] + weight;
				setds.insert(make_pair(distance[neighbour], neighbour));
			}
		}
	}
	
	printf("Vertex	Distance from Source\n");
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
