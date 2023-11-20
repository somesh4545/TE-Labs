#include <bits/stdc++.h>
using namespace std;

struct item
{
    int w;
    int p;
};

void merge(item items[], int start, int mid, int end)
{
    int lsize = mid - start + 1;
    int rsize = end - mid;
    item larr[lsize], rarr[rsize];
    for (int i = 0; i < lsize; i++)
        larr[i] = items[start + i];
    for (int i = 0; i < rsize; i++)
        rarr[i] = items[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < lsize && j < rsize)
    {
        if (larr[i].w > rarr[j].w)
        {
            items[k++] = rarr[j++];
        }
        else
        {
            items[k++] = larr[i++];
        }
    }

    while (i < lsize)
        items[k++] = larr[i++];
    while (j < rsize)
        items[k++] = rarr[j++];
}

void sortR(item items[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    sortR(items, start, mid);
    sortR(items, mid + 1, end);
    merge(items, start, mid, end);
}

int main()
{
    // Number of objects n = 4, Knapsack Capacity M = 5,
    // Weights(W1, W2, W3, W4) = (2, 3, 4, 5) and profits(P1, P2, P3, P4) = (3, 4, 5, 6).
    int n = 4;
    int m = 5;
    item items[n];

    items[0].w = 2, items[1].w = 3, items[2].w = 4, items[3].w = 5;
    items[0].p = 3, items[1].p = 4, items[2].p = 5, items[3].p = 6;

    sortR(items, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << items[i].p << " " << items[i].w << endl;
    }
    cout << endl
         << endl;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (items[i - 1].w > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {

                dp[i][j] = max(dp[i - 1][j], items[i - 1].p + dp[i - 1][j - items[i - 1].w]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}