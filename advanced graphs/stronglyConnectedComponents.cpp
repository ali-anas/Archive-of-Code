#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<int>* edges, int start, unordered_set<int>& visited, stack<int>& finishedVertex) {
	visited.insert(start);
	for(int i = 0; i < edges[start].size(); i++) {
		int adjacent = edges[start][i];
		if(visited.count(adjacent) == 0) {
			dfs1(edges, adjacent, visited, finishedVertex);
		}
	}
	finishedVertex.push(start);
}

void dfs2(vector<int>* edgesT, int start, unordered_set<int>* component, unordered_set<int>& visited) {
	visited.insert(start);
	component -> insert(start);
	for(int i = 0; i < edgesT[start].size(); i++) {
		int adjacent = edgesT[start][i];
		if(visited.count(adjacent) == 0) {
			dfs2(edgesT, adjacent, component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, vector<int>* edgesTranspose, int n) {
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for(int i = 0; i < n; i++) {
		if(visited.count(i) == 0) {
			dfs1(edges, i, visited, finishedVertices);
		}
	}
	
	visited.clear();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(finishedVertices.size() != 0) {
		int topElement = finishedVertices.top();
		finishedVertices.pop();
		if(visited.count(topElement) != 0) {
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesTranspose, topElement, component, visited);
		output -> insert(component);
	}
	return output;
}

int main() {
	int n;
	cin >> n;
	vector<int>* edges = new vector<int>[n]; // graph
	vector<int>* edgesTranspose = new vector<int>[n]; // transpose of graph
	
	int noOfEdges;
	cin >> noOfEdges;
	
	for(int i = 0; i < noOfEdges; i++) {
		int source, dest;
		cin >> source >> dest;
		edges[source - 1].push_back(dest - 1);
		edgesTranspose[dest - 1].push_back(source - 1);
	}
	
	unordered_set<unordered_set<int>*>* components = getComponents(edges, edgesTranspose, n);
	
	unordered_set<unordered_set<int>*>::iterator it = components -> begin();
	while(it != components -> end()) {
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component -> begin();
		while(it2 != component -> end()) {
			cout << *it2 + 1<< " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	}
	
	delete components;
	delete []edges;
	delete []edgesTranspose;
	return 0;
}
