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

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, vector<int>* edgesTranspose,int n) {
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
	
	#warning TODO get working code from coding ninjas problem
	while(1) {
		int v;
		cin >> v;
		if(v == 0) {
			break;
		}
		int e;
		cin >> e;
		vector<int> *edges = new vector<int>[v];
		vector<int> *edgesT = new vector<int>[v];
		
		for(int i = 0; i < e; i++) {
			int j, k;
			cin >> j >> k;
			edges[j-1].push_back(k - 1);
			edgesT[k-1].push_back(j-1);
		}
		
		unordered_set<unordered_set<int>*>* components = getComponents(edges, edgesT, v);
		
		unordered_set<unordered_set<int>*>::iterator it = components -> begin();
		vector<int> ans;
		while(it != components -> end()) {
			bool edgeToOther = false;
			unordered_set<int>* component = *it;
			unordered_set<int>::iterator it2 = component -> begin();
			while(it2 != component -> end()) {
				int vertex = *it2;
				for(int i = 0; i < edges[vertex].size(); i++) {
					if(component.find(edges[vertex][i]) == component -> end()) {
						edgeToOther = true;
						break;
					}
				}
				if(edgeToOther) {
					break;
				}
				it2++;
			}
			if(!edgeToOther) {
				it2 = component -> begin()
				while(it2 != component -> end()) {
					ans.push_back(*it2 + 1);
					it2++;
				}
			}
			delete component;
			it++;
		}
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		
		delete []edges;
		delete []edgesT;
		delete components;
		cout << "\n";
	}
	return 0;
}
