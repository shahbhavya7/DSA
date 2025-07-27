#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;         
    vector<vector<int>> adj; 

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> dfsTraversalstack(int start)
    {
        vector<int> dfs;       // Vector to store DFS traversal order
        vector<int> vis(V, 0); // Visited array to track visited nodes
        stack<int> s;

        s.push(start); // Push the starting node onto the stack

        while (!s.empty())
        {                       // While there are nodes to process
            int node = s.top(); // Get the top node from the stack
            s.pop();            // Remove the top node from the stack as it is being processed

            if (!vis[node])
            {                        // If the node has not been visited
                vis[node] = 1;       // Mark it as visited
                dfs.push_back(node); // Add the node to the DFS result

                for (int neighbor : adj[node])
                { // Iterate through all adjacent nodes of the current node
                    if (!vis[neighbor])
                    {                     // If the neighbor has not been visited
                        s.push(neighbor); // Push the neighbor onto the stack for further processing
                    }
                }
            }
        }

        return dfs;
    }

    void dfsTraversalhelper(int start, vector<int> &vis, vector<int> &dfs)
    {
        vis[start] = 1;
        dfs.push_back(start);
        for (int neighbor : adj[start])
        {
            if (!vis[neighbor])
            {
                dfsTraversalhelper(neighbor, vis, dfs);
            }
        }
    }

    vector<int> dfsTraversalRec(int start)
    {
        vector<int> dfs;                     // Vector to store DFS traversal order
        vector<int> vis(V, 0);               // Visited array to track visited nodes
        dfsTraversalhelper(start, vis, dfs); // Call the stack-based DFS traversal function
        return dfs;
    }
};

class Solution
{
public:
    void printVector(const vector<int> &vec)
    { 
        cout << "DFS Traversal: ";
        for (int val : vec)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    Graph g(11); 

    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(7, 8);
    g.addEdge(7, 10);
    g.addEdge(8, 9);

    Solution sol;
    vector<int> dfs = g.dfsTraversalRec(1); 
    sol.printVector(dfs);                   

    return 0;
}