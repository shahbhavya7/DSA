#include<bits/stdc++.h>
using namespace std;

// Graph Introduction : Adjacency List Representation for directed graphs
int main(){
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<int> adj[n + 1]; // Adjacency list representation - 
    //- you get an array named adj where each index, from adj[0] to adj[n], holds a separate vector<int>
    for(int i = 0; i < m; i++){
        cout << "Enter edge (u v): ";
        int u, v; // u -> v
        cin >> u >> v;
        adj[u].push_back(v); // Add edge from u to v i.e at index uth index of arr adj, we add v to vector present at that index
    }
    // Output the adjacency list
    cout << "Adjacency List:" << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " -> "; // Print vertex number
        for(int v : adj[i]){ // Iterate through all vertices adjacent to i, i.e print all elements of vector at index i
            cout << v << " "; // Print all vertices adjacent to i
        }
        cout << endl;
    }
    return 0;
}