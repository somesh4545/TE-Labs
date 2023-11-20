#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u;
    int v;
    int cost;
};

int main()
{
    int v = 7;
    int e = 9;
    edge edges[e];

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        cout << i << endl;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u - 1, v = edges[j].v - 1;
            int cost = edges[j].cost;
            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
            }
        }
    }

    for (int i = 0; i < v - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u - 1, v = edges[j].v - 1;
            int cost = edges[j].cost;
            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                flag = true;
                cout << "\n\nNegative edge cycle is present\n";
                break;
            }
        }
        if (flag == true)
            break;
    }
    cout << endl
         << endl;

    cout << "Vertex\tDistance from source\n";

    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << dist[i] << "\n";
    }
    return 0;
}