#include <bits/stdc++.h>
using namespace std;


// method to store a graph using adjacency matrix method
int main(){
    cout << "Enter the number of nodes and edges: " << endl;
    int n, m; 
    cin >> n >> m; 
    vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));


    // initialising the matrix to zero 
    for(int i = 0 ; i <= n; i++){
        for(int j = 0; j<=n ; j++){
            adj[i][j] = 0;
        }
    }

    // marking the edges as 1
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin>> u>>v;

        adj[u][v] = true;
        adj[v][u] = true;

    }


    // printing the adjacency matrix
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1 ; j++){
            cout<<adj[i][j] << ' ';
        }cout << endl;
    }
    return 0;
}