#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

struct Edge // to store the graph data in vector of type Edge
{
    int src, dest, weight;
};

void primMSTRec(vector<vector<pair<int, int>>> &graph, int V, vector<int> &key, vector<bool> &mstSet, vector<int> &parent, int u)
{
    mstSet[u] = true; // marking the starting node true in mst

    for (auto &neighbor : graph[u]) // finding all neighbours that are not in mst
    {
        int v = neighbor.first;
        int weight = neighbor.second;

        if (!mstSet[v] && weight < key[v])
        {
            key[v] = weight;
            parent[v] = u;
        }
    }

    int minKey = INF;
    int nextVertex = -1;
    for (int v = 0; v < V; ++v)
    {
        if (!mstSet[v] && key[v] < minKey)
        {
            minKey = key[v];
            nextVertex = v;
        }
    }

    if (nextVertex != -1)
    {
        primMSTRec(graph, V, key, mstSet, parent, nextVertex);
    }
}

void primMST(vector<vector<pair<int, int>>> &graph, int V)
{
    vector<int> key(V, INF);
    vector<bool> mstSet(V, false);
    vector<int> parent(V, -1);

    int src = 0;
    key[src] = 0;

    primMSTRec(graph, V, key, mstSet, parent, src);

    cout << "Edge \t\tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t\t" << key[i] << endl;
}

int main()
{
    int V = 5; // Number of vertices
    int E = 7; // Number of edges
    vector<vector<pair<int, int>>> graph(V);
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};

    for (auto &edge : edges)
    {
        graph[edge.src].push_back(make_pair(edge.dest, edge.weight));
        graph[edge.dest].push_back(make_pair(edge.src, edge.weight));
    }

    primMST(graph, V);
    return 0;
}

// int V, E; // Number of vertices and edges
//     cout << "Enter number of vertices and edges: ";
//     cin >> V >> E;

//     // Adjacency list representation of the weighted graph
//     vector<vector<pair<int, int>>> graph(V);

//     cout << "Enter edges and weights (src dest weight): \n";
//     for (int i = 0; i < E; ++i)
//     {
//         int src, dest, weight;
//         cin >> src >> dest >> weight;
//         graph[src].push_back(make_pair(dest, weight));
//         graph[dest].push_back(make_pair(src, weight)); // Undirected graph
//     }

//     // Call primMST function
//     primMST(graph, V);

// void primMST(vector<vector<pair<int, int>>> &graph, int V)
// {
//     vector<int> key(V, INF);
//     vector<int> parent(V, -1);
//     vector<bool> mstSet(V, false);

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     int src = 0;
//     pq.push(make_pair(0, src));
//     key[src] = 0;

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();
//         mstSet[u] = true;

//         for (auto &neighbor : graph[u])
//         {
//             int v = neighbor.first;
//             int weight = neighbor.second;

//             if (!mstSet[v] && weight < key[v])
//             {
//                 key[v] = weight;
//                 pq.push(make_pair(weight, v));
//                 parent[v] = u;
//             }
//         }
//     }

//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < V; ++i)
//         cout << parent[i] << " - " << i << "\t" << key[i] << endl;
// }