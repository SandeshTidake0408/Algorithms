#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define max INT32_MAX

void Dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, max);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &i : graph[u])
        {
            int v = i.first;
            int weight = i.second;

            if ((dist[u] + weight) < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main()
{
    vector<vector<pair<int, int>>> graph =
        {
            {{1, 10}, {2, 6}, {3, 5}},
            {{0, 10}, {3, 15}},
            {{0, 6}, {3, 4}},
            {{0, 5}, {1, 15}, {2, 4}}};

    Dijkstra(graph,0);

    return 0;
}
