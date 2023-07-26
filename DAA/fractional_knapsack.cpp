#include <bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int profit;
    double pbyw; //profit by weight ratio
};

// merge sort function
void mergesort(item items[], int start, int end){
    if(start>=end) return;
    int mid = (end+start)/2;

    mergesort(items, start, mid);
    mergesort(items, mid);
}

int main(){

    int n, maxWeight;
    cout << "Enter the count of items: ";
    cin >> n;
    cout << "Enter capacity of bag: ";
    cin >> maxWeight;

    item items[n];

    cout << "Enter the items weight: ";
    int w;
    for(int i=0; i<n; i++){
        cin >> w;
        items[i].weight = w;
    }
    cout << "Enter the items profit: ";
    int p;
    for(int i=0; i<n; i++){
        cin >> p;
        items[i].profit = p;
    }
    return 0;
}