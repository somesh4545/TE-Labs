#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, cost;
};

int main()
{

    int v;
    cin >> v;
    int e;
    cin >> e;
    edge edges[e];
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    vector<vector<int>> path(v);
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u - 1, v = edges[j].v - 1;
            int cost = edges[j].cost;

            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                vector<int> temp = path[u];
                temp.push_back(u + 1);
                // temp.push_back(v + 1);
                path[v] = temp;
                dist[v] = dist[u] + cost;
            }
        }
    }

    cout << "\n\n";
    for (auto p : path)
    {
        for (auto ele : p)
            cout << ele << " ";
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << dist[i] << "\n";
    }

    return 0;
}