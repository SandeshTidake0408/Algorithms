#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void Union(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

bool comp(vector<int> a, vector<int> b) // comparator
{
    return a[2] < b[2];
}

void KruskalMST(vector<vector<int>> &edges, int V)
{

    vector<int> result;
    vector<int> parent(V);
    vector<int> rank(V);

    sort(edges.begin(), edges.end(), comp);

    for (int v = 0; v < V; v++)
    {
        parent[v] = v;
        rank[v] = 0;
    }
    int E = edges.size();

    // while (result.size() < V - 1 && i < E)/
    for (int i = 0; i < V && i < E; i++)
    {

        vector<int> next_edge = edges[i];

        int x = find(parent, next_edge[0]);
        int y = find(parent, next_edge[1]);

        if (x != y)
        {
            result.push_back(i);
            Union(parent, rank, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    for (int i = 0; result.size(); i++)
    {
        cout << edges[result[i]][0] << " -- "
             << edges[result[i]][1] << " == "
             << edges[result[i]][2] << endl;
    }
}

int main()
{

    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    KruskalMST(edges, 4);

    return 0;
}