#include <bits/stdc++.h>

using namespace std;

struct item
{
    float weight;
    float profit;
    float profit_by_weight;
};

void merge(struct item items[], int l, int mid, int r)
{
    int lsize = mid - l + 1;
    int rsize = r - mid;
    struct item larr[lsize], rarr[rsize];

    for (int i = 0; i < lsize; i++)
        larr[i] = items[l + i];
    for (int i = 0; i < rsize; i++)
        rarr[i] = items[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < lsize && j < rsize)
    {
        if (larr[i].profit_by_weight > rarr[j].profit_by_weight)
        {
            items[k++] = larr[i++];
        }
        else
        {
            items[k++] = rarr[j++];
        }
    }
    while (i < lsize)
        items[k++] = larr[i++];
    while (j < rsize)
        items[k++] = rarr[j++];
}

void sortR(struct item items[], int start, int end)
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
    // w = (5, 10, 20, 30, 40) and Profit
    //     p = (30, 20, 100, 90, 160).

    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    struct item items[n];
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].profit;
        items[i].profit_by_weight = items[i].profit / items[i].weight;
    }

    sortR(items, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << items[i].profit << " " << items[i].weight << " " << items[i].profit_by_weight << endl;
    }
    cout << endl
         << endl;

    int inbag = 0;
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (inbag + items[i].weight <= capacity)
        {
            inbag += items[i].weight;
            totalProfit += items[i].profit;
            cout << "Full consider " << items[i].profit << " Profit till " << totalProfit << endl;
        }
        else
        {
            int profit = items[i].profit_by_weight * (capacity - inbag);
            totalProfit += profit;
            cout << "Half consider " << profit << " Profit till " << totalProfit << endl;
            break;
        }
    }

    return 0;
}
