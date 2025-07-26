#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices; 
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for directed graph
    }

    vector<int> bfsTraversal(int start = 0) {
        vector<int> bfs;  // Vector to store BFS traversal order
        vector<int> vis(V, 0); // Visited array to track visited nodes
        queue<int> q;

        vis[start] = 1; // Mark the starting node as visited
        q.push(start); // Enqueue the starting node

        while (!q.empty()) { // While there are nodes to process
            int node = q.front(); // Get the front node from the queue
            q.pop();
            bfs.push_back(node); // Add the node to the BFS result

            for (int neighbor : adj[node]) { // Iterate through all adjacent nodes of the current node
                if (!vis[neighbor]) { // If the neighbor has not been visited
                    vis[neighbor] = 1; // Mark it as visited
                    q.push(neighbor); // Enqueue the neighbor for further processing
                } 
            }
        }

        return bfs;
    }
};

class Solution {
public:
    void printVector(const vector<int>& vec) { // Function to print the BFS traversal result
        cout << "BFS Traversal: ";
        for (int val : vec)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    Graph g(11); // Create a graph with 6 vertices

    g.addEdge(1,7);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(7, 8);
    g.addEdge(7, 10);
    g.addEdge(8, 9);    

    Solution sol;
    vector<int> bfsResult = g.bfsTraversal(1);
    sol.printVector(bfsResult);

    return 0;
}
