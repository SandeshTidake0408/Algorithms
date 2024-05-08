#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>> &graph, vector<int> &color, int col)
{
    // for (int i = 0; i < graph[node].size(); ++i)
    //     if (graph[node][i] && col == color[i])
    //         return false;
    // return true;

    for (int it : graph[node])
    {
        if (color[it] == col)
            return false;
    }

    return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

void graphColoring(vector<vector<int>> &graph, int m)
{
    vector<int> color(graph.size(), 0);

    if (!graphColoringUtil(graph, m, color, 0))
        cout << "Solution does not exist.";
    else
    {
        cout << "Solution Exists: Following are the assigned colors \n";
        for (int i = 0; i < color.size(); ++i)
            cout << "Color assigned to vertex " << i << " is " << color[i] << "\n";
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// class Graph
// {
// public:
//     vector<vector<int>> adj;
//     vector<int> color;

//     Graph(int n)
//     {
//         adj.resize(n);
//         color.resize(n, 0);
//     }

//     void addEdge(int u, int v)
//     {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void print()
//     {
//         for (int i = 0; i < adj.size(); ++i)
//         {
//             cout << i << " -> ";
//             for (int j = 0; j < adj[i].size(); ++j)
//             {
//                 cout << adj[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }

//     bool isSafe(int node, vector<vector<int>> &adj, vector<int> &color, int col)
//     {

//         for (int it : adj[node])
//         {
//             if (color[it] == col)
//                 return false;
//         }

//         return true;
//     }

//     bool ColorGraph(int node, int n, int m, vector<vector<int>> &adj, vector<int> &color)
//     {

//         if (node == n)
//             return true;

//         for (int i = 1; i <= m; i++)
//         {
//             if (isSafe(node, adj, color, i))
//             {
//                 color[node] = i;
//                 if (ColorGraph(node + 1, n, m, adj, color))
//                     return true;
//                 color[node] = 0;
//             }
//         }

//         return false;
//     }
// };

// int main()
// {

//     int n;
//     cout << "enter n+1 edges" << endl;
//     cin >> n;

//     if (!n)
//         cout << "please provide the vertices value" << endl;

//     Graph g = Graph(n);
//     int numEdges = 0;
//     int u, v;
//     while (numEdges < n - 1)
//     {
//         cout << "Enter the value of u and v: ";
//         cin >> u >> v;
//         g.addEdge(u, v);
//         numEdges++;
//     }
//     //  g.print();

//     int m;
//     cout << "enter the number of color" << endl;
//     cin >> m;

//     cout << g.ColorGraph(0, n, m, g.adj, g.color);

//     return 0;
// }