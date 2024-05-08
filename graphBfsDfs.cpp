// 1.Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected
// graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
// structure.

#include <iostream>
#include <vector>
#include <queue>
// #include <unordered_set>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v])
        {
            if (!visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i : adj[v])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(5); // Create a graph with 5 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
