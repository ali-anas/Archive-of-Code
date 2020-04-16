#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll getComponentTotal(const vector<int>& comp, const ll* a) {
	ll ans = 0;
	for(int i = 0; i < comp.size(); i++) {
		ans += a[comp[i]];
	}
	return ans;
}

void getComponentDFS(vector<int>* edges, int start, bool* visited, vector<int>& comp) {
	visited[start] = true;
	comp.push_back(start);
	for(int i = 0; i < edges[start].size(); i++) {
		int adj = edges[start][i];
		if(!visited[adj]) {
			getComponentDFS(edges, adj, visited, comp);
		}
	}
	return;
}

ll getAns(vector<int>* edges, ll* a, int n) {
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++) {
		visited[i] = false;
	}
	
	ll maxBananas = 0;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			vector<int> component;
			getComponentDFS(edges, i, visited, component);
			ll componentTotal = getComponentTotal(component, a);
			maxBananas = max(componentTotal, maxBananas);
		}
	}
	delete []visited;
	return maxBananas;
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;
		vector<int>* edges = new vector<int>[n];
		for(int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);
		}
		ll* a = new ll[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		ll ans = getAns(edges, a, n);
		cout << ans << endl;
		delete []a;
		delete []edges;
	}
}
