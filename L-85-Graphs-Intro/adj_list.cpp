#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter the number of nodes and edges: " << endl;
    int n, m; 
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m ; i++){
        int u, v;
        cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // since the graph is undirected
    }

    for (int i = 0; i<n; i++){
        cout << i << " -> ";
        for(auto j : adj[i]){
            cout << j << ' ';
        }cout << endl;
    }
    return 0;
}