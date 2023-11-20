#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

class Node
{
public:
    vector<vector<int>> graph;
    int vertex;
    Node() {}
    Node(int v, vector<vector<int>> g)
    {
        this->vertex = v;
        this->graph = g;
    }

    int costCalc(int r, int c)
    {
        int n = graph.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == r || j == c)
                {
                    graph[i][j] = inf;
                }
            }
        }
        graph[c][r] = inf;
        int cost = 0;
        cout << "\nCalulcating minimum row: ";
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                mini = min(mini, graph[i][j]);
            }
            if (mini == inf)
                mini = 0;
            cout << mini << " ";
            cost += mini;
            for (int j = 0; j < n; j++)
                if (graph[i][j] != INT_MAX)
                    graph[i][j] -= mini;
        }
        cout << "\nCalulcating minimum column: ";
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < n; j++)
                mini = min(mini, graph[j][i]);
            if (mini == inf)
                mini = 0;
            cout << mini << " ";
            cost += mini;
            for (int j = 0; j < n; j++)
                if (graph[j][i] != INT_MAX)
                    graph[j][i] -= mini;
        }
        return cost;
    }
};

int main()
{
    vector<vector<int>> graph = {{inf, 20, 30, 10, 11}, {15, inf, 16, 4, 2}, {3, 5, inf, 2, 4}, {19, 16, 18, inf, 3}, {16, 4, 7, 16, inf}};

    Node root(1, graph);
    int totalCost = root.costCalc(-1, -1);

    Node last = root;
    vector<int> visited(graph.size());
    visited[0] = 1;

    int n = graph.size(), i = 1;

    while (i < n)
    {
        Node temp;
        int mini = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            if (visited[k] == 1)
                continue;
            Node tri(k + 1, last.graph);
            int cost = tri.costCalc(last.vertex - 1, k) + totalCost + last.graph[last.vertex - 1][k];
            cout << "\nThe cost of vertex  " << k + 1 << " is " << cost << "\n\n";
            if (cost < mini)
            {
                mini = cost;
                temp = tri;
            }
        }
        last = temp;
        totalCost = mini;
        cout << "\n\nPicked vertex " << last.vertex << "\n\n";
        visited[last.vertex - 1] = 1;
        i++;
    }

    return 0;
}