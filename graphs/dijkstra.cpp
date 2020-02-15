#include <iostream>
#include <climits>
using namespace std;

int findMinDistantVertex(int* distance, bool* visited, const int &v) {
    int ans = -1;
    for(int i = 0; i < v; i++) {
        if(!visited[i] && (ans == -1 || distance[i] < distance[ans])) {
            ans = i;
        }
    }
    // cout << "ans" << ans << endl;
    return ans;
}

void dijkstra(int** adj, const int &v) {
    int* distance = new int[v];
    bool* visited = new bool[v];
    for(int i = 0; i<v; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[0] = 0;
    
    for(int i = 0; i < v-1; i++) {
        int vertex = findMinDistantVertex(distance, visited, v);
        visited[vertex] = true;
        for(int j = 0; j < v; j++) {
            if(!visited[j] && adj[vertex][j] != 0) {
                if(adj[vertex][j]+distance[vertex] < distance[j]) {
                    distance[j] = adj[vertex][j]+distance[vertex];
                }
            }
        }
    }
    
    for(int i = 0; i< v; i++) {
        cout << i << " " << distance[i] << endl;
    }
    delete []visited;
    delete []distance;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int** adj = new int*[v];
    for(int i = 0; i < v; i++) {
        adj[i] = new int[v];
        for(int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }
    
    for(int j = 0; j < e; j++) {
        int s, d, w;
        cin >> s >> d >> w;
        adj[s][d] = w;
        adj[d][s] = w;
    }
    
    dijkstra(adj, v);
    
    for(int i = 0; i < v; i++) {
        delete []adj[i];
    }
    delete []adj;
    return 0;
}