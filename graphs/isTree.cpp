#include <bits/stdc++.h>
using namespace std;

bool dfsDetectCycle(vector<int>* edges, bool* visited, int start, int parent) {
    visited[start] = true;
    for(int i = 0; i < edges[start].size(); i++) {
        int vertex = edges[start][i];
        if(!visited[vertex]) {
            if(dfsDetectCycle(edges, visited, vertex, start)) {
                return true;
            }
        } 
        else if(vertex != parent) {
                return true;
        }
    }
    return false;
}

bool Tree(vector<int>* edges , const int& n, const int& m) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

    if(dfsDetectCycle(edges, visited, 0, -1)) {
        delete []visited;
        return false;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            delete []visited;
            return false;
        }
    }
    delete []visited;
    return true;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        edges[s-1].push_back(d-1);
        edges[d-1].push_back(s-1);
    }

    if(Tree(edges, n, m)) {
        printf("YES\n");
    } 
    else {
        printf("NO\n");
    }
    delete []edges;
    return 0;
}