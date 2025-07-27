#include<bits/stdc++.h>
using namespace std;

// Graph Introduction : Adjacency Matrix Representation for directed graphs
int main(){
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    int adj[n + 1][n + 1] = {0}; // Adjacency matrix representation initialized to 0
    for(int i = 0; i < m; i++){
        cout << "Enter edge (u v): ";
        int u, v; // u -> v
        cin >> u >> v;
        adj[u][v] = 1; // Add edge from u to v
    }
    // Output the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j] << " "; // Print 1 if edge exists, else 0
        }
        cout << endl;
    }
    cout << "Adjacency Matrix Representation of the Graph complete" << endl;

    return 0;
}