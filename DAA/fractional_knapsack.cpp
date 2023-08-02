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
// type parameter is used for sorting based on profit by weight ratio(1), by profit(2), by weight(3)
void merge(item items[], int start, int mid, int end, int type){
    int lSize = mid-start+1;
    int rSize = end-mid;

    item lArr[lSize];
    item rArr[rSize];
    for(int i=0; i<lSize; i++) lArr[i] = items[i+start];
    for(int i=0; i<rSize; i++) rArr[i] = items[i+mid+1];

    int i=0, j=0, k=start;
    while(i<lSize && j<rSize){
        if(type==1){
            if(lArr[i].pbyw > rArr[j].pbyw){
                items[k++] = lArr[i++];
            }else{
                items[k++] = rArr[j++];
            }
        }
        if(type==2){
            if(lArr[i].profit > rArr[j].profit){
                items[k++] = lArr[i++];
            }else{
                items[k++] = rArr[j++];
            }
        }
        if(type==3){
            if(lArr[i].weight > rArr[j].weight){
                items[k++] = lArr[i++];
            }else{
                items[k++] = rArr[j++];
            }
        }
    }

    while(i<lSize) items[k++] = lArr[i++];
    while(j<rSize) items[k++] = rArr[j++];
}

// merge sort function
// type parameter is used for sorting based on profit by weight ratio(1), by profit(2), by weight(3)
void mergesort(item items[], int start, int end, int type){
    if(start>=end) return;
    
    int mid = (end+start)/2;

    mergesort(items, start, mid, type);
    mergesort(items, mid+1, end, type);
    merge(items, start, mid, end, type);
}

void calc_profit(int maxWeight, item items[], int n){
    cout << "item picked" << endl;
    cout << "Item weight\t item profit \t total profit"<<endl;
    int total_profit= 0;
    for(int i=0; i<n; i++){
        if(maxWeight - items[i].weight >= 0){
            maxWeight -= items[i].weight;
            total_profit += items[i].profit;
            cout << prd(items[i].weight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << "\n";
        
        }else{
            total_profit += (maxWeight/items[i].weight) * items[i].profit;
            string str =  (maxWeight>0) ? "yes - original weight= "+to_string(items[i].weight): "no";
            cout << prd(maxWeight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << " | Picked ?" << str << "\n";
            break;
        }
    }
    cout << "\nTotal profit is: " << total_profit << endl;

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
    
    
    cout << "\n\nBased on profit by weight ration\n";
    mergesort(items, 0, n-1, 1);
    calc_profit(maxWeight, items, n);


    cout << "\n\nBased on profit\n";
    mergesort(items, 0, n-1, 2);
    calc_profit(maxWeight, items, n);

    cout << "\n\nBased on weight\n";
    mergesort(items, 0, n-1, 3);
    calc_profit(maxWeight, items, n);

    return 0;
}


//1-a : theory