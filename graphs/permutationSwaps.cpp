#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int>& visited, unordered_set<int>* component) {
	visited.insert(start);
	component -> insert(start);
	
	vector<int>::iterator it = edges[start].begin();
	for( ; it != edges[start].end(); it++) {
		int i = *it;
		if(visited.count(i) > 0) {
			continue;
		}
		dfs(edges, i, visited, component);
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
	unordered_set<int> visited;
	
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	
	for(int i = 0; i < n; i++) {
		if(visited.count(i) == 0) {
			unordered_set<int>* component = new unordered_set<int>();
			dfs(edges, i, visited, component);
			output -> insert(component);
		}
	}
	return output;
} 

int main() {
	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; i++) {
		int n, m;
		cin >> n >> m;
		vector<int>* edges = new vector<int>[n];
		int* p = new int[n];
		int* q = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> q[i];
		}
		for(int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);
		}
		
		bool ans = true;
		
		unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
		
		unordered_set<unordered_set<int>*>::iterator it1 = components -> begin();
		while(it1 != components -> end()) {
			unordered_set<int>* component = *it1;
			unordered_set<int> check;
			unordered_set<int>::iterator it2 = component -> begin();
			while(it2 != component -> end()) {
				int index = *it2;
				check.insert(p[index]);
				it2++;
			}
			it2 = component -> begin();
			while(it2 != component -> end()) {
				int index = *it2;
				int qElement = q[index];
				unordered_set<int>::iterator it3 = check.find(qElement);
				if(it3 == check.end()) {
					ans = false;
					break;
				}
				it2++;
			}
			delete component;
			it1++;
		}
		
		if(ans) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		delete components;
		delete edges;
	}
	return 0;
}
