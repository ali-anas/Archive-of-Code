int **adj = new int*[V];
    for(int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++) {
        int j, k;
        cin >> j >> k;
        adj[j][k] = 1;
        adj[k][j] = 1;
    }
    
    cin >> start >> end;
    
    bool* visited = new bool[V];
    for(int i= 0; i < V; i++) {
        visited[i] = false;
    }
    
    
    for(int i = 0; i < V; i++) {
        delete []adj[i];
    }
    
    delete []adj;
    delete []visited;





    queue<int> pendingNodes;
    pendingNodes.push(0);
    visited[0] = true;
    while(!pendingNodes.empty()) {
        int curr = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0; i < v; i++) {
            if(i == curr) {
                continue;
            }
            if(!visited[i] && adj[curr][i] == 1) {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }