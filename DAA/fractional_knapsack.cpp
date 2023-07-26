#include <bits/stdc++.h>
using namespace std;

struct item{
    float weight;
    float profit;
    float pbyw; //profit by weight ratio
};

string prd(const float x, const int decDigits, const int width) {
    stringstream ss;
    ss << fixed << right;
    ss.fill(' ');        // fill space around displayed #
    ss.width(width);     // set  width around displayed #
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

// merge function
void merge(item items[], int start, int mid, int end){
    int lSize = mid-start+1;
    int rSize = end-mid;

    item lArr[lSize];
    item rArr[rSize];
    for(int i=0; i<lSize; i++) lArr[i] = items[i+start];
    for(int i=0; i<rSize; i++) rArr[i] = items[i+mid+1];

    int i=0, j=0, k=start;
    while(i<lSize && j<rSize){
        if(lArr[i].pbyw > rArr[j].pbyw){
            items[k++] = lArr[i++];
        }else{
            items[k++] = rArr[j++];
        }
    }

    while(i<lSize) items[k++] = lArr[i++];
    while(j<rSize) items[k++] = rArr[j++];
}

// merge sort function
void mergesort(item items[], int start, int end){
    if(start>=end) return;
    
    int mid = (end+start)/2;

    mergesort(items, start, mid);
    mergesort(items, mid+1, end);
    merge(items, start, mid, end);
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
        items[i].pbyw = items[i].profit/items[i].weight;
    }

    cout << "\n\nAvailable data\n";
    cout << "Items: " << n << endl;
    cout << "Capacity: " << maxWeight << endl << endl;
    
    mergesort(items, 0, n-1);
    
    cout << "Item weight\t item profit \t porfit by weight"<<endl;
    for(int i=0; i<n; i++){
        cout << prd(items[i].weight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(items[i].pbyw, 2, 10) << "\n";
    }

    cout << endl << endl;
    cout << "item picked" << endl;
    cout << "Item weight\t item profit \t total profit"<<endl;
    int total_profit= 0;
    for(int i=0; i<n; i++){
        if(maxWeight-items[i].weight >= 0){
            maxWeight -= items[i].weight;
            total_profit += items[i].profit;
            cout << prd(items[i].weight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << "\n";
        
        }else{
            total_profit += (maxWeight/items[i].weight) * items[i].profit;
            cout << prd(maxWeight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << "\n";

        }
    }
    cout << "\nTotal profit is: " << total_profit << endl;

    return 0;
}