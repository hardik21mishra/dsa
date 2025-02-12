#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    visited[0] = 1;
    vector<int> ans;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (0-based index):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line if the graph is directed
    }

    vector<int> bfsResult = bfsOfGraph(adj);

    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
