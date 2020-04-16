#include<bits/stdc++.h>
using namespace std;

int getLevelBFS(vector<int>* graph, int n, int m) {
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++) {
		visited[i] = false;
	}
    int* dp = new int[n];
    for(int i = 0; i < n; i++) {
		dp[i] = -1;
	}
	
    dp[0] = 0;
	queue<int> pending;
	pending.push(0);
	visited[0] = true;
	
	while(!pending.empty()) {
		int front = pending.front();
		pending.pop();
		
		for(int i = 0; i < graph[front].size(); i++) {
            int adj = graph[front][i];
			if(!visited[adj]) {
				visited[adj] = true;
				pending.push(adj);
                dp[adj] = dp[front] + 1;
			}
		}
	}
    int ans = dp[n-1];
	delete []visited;
    delete []dp;
	return ans;
}

int main()
{
	//code
    int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;
		vector<int>* graph = new vector<int>[n];
        for(int i = 0; i < m; i++) {
            int j, k;
            cin >> j >> k;
            graph[j-1].push_back(k-1);
            graph[k-1].push_back(j-1);
        }
		
		int level = getLevelBFS(graph, n, m);
		cout << level << "\n";
		delete []graph;
	}
	return 0;
}
