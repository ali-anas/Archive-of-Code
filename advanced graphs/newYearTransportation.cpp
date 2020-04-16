#include <bits/stdc++.h>
using namespace std;

bool findPathBFS(vector<int>* edges, int n, int t) {
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++) {
		visited[i] = false;
	}
	
	bool ans = false;
	queue<int> pending;
	pending.push(0);
	visited[0] = true;
	while(!pending.empty()) {
		int front = pending.front();
		pending.pop();
		if(front == t) {
			ans = true;
			break;
		}
		
		for(int i = 0; i < edges[front].size(); i++) {
			int adj = edges[front][i];
			if(!visited[adj]) {
				visited[adj] = true;
				pending.push(adj);
			}
		}
	}
	delete []visited;
	return ans;
}

int main() {
	int n, t;
	cin >> n >> t;
	vector<int>* edges = new vector<int>[n-1];
	for(int i = 0; i < n-1; i++) {
		int a;
		cin >> a;
		edges[i].push_back(i+a);
	}
	bool foundPath = findPathBFS(edges, n-1, t-1);
	if(foundPath) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	delete []edges;
	return 0;
}
