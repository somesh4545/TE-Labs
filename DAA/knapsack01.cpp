#include<bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int profit;
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
            if(lArr[i].weight < rArr[j].weight){
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

// type parameter for fractional knapsack or 1/0 based
void calc_profit(int capacity, item items[], int n, int type){
    cout << "item picked" << endl;
    cout << "Item weight\t item profit \t total profit"<<endl;
    int total_profit= 0;
    for(int i=0; i<n; i++){
        if(capacity - items[i].weight >= 0){
            capacity -= items[i].weight;
            total_profit += items[i].profit;
            cout << prd(items[i].weight, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << "\n";
        
        }else{
            if(type == 1){
                total_profit += (capacity/items[i].weight) * items[i].profit;
                string str =  (capacity>0) ? "yes - original weight= "+to_string(items[i].weight): "no";
                cout << prd(capacity, 0, 15) << " | " << prd(items[i].profit, 0, 15) << " | " <<prd(total_profit, 2, 10) << " | Picked ?" << str << "\n";
                capacity = 0; 
            }
            if(capacity == 0) break;
        }
    }
    cout << "\nTotal profit is: " << total_profit << endl;
    cout << "Is bag empty: " << (capacity<=0 ? "no" : "yes") << endl;
}


int find_max_profit(item items[], int capacity, int n){
    char ch;
    cout << "Do you want to view whch items are picked(y/n): ";
    cin >> ch;

    int result = 0;

    int dp[n+1][capacity+1];

    // setting row1 and column1 as zero
    for(int i=0; i<capacity+1; i++) dp[0][i] = 0;
    for(int i=0; i<n+1; i++) dp[i][0] = 0;
    cout << "\nDP table\n";
    for(int i=1; i<n+1; i++){
        for(int j=1; j<capacity+1; j++){
            if(items[i-1].weight > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(items[i-1].profit+dp[i-1][j-items[i-1].weight], dp[i-1][j]);
            }
            cout << dp[i][j] << " ";
        }
        cout <<  endl;
    }

    if(ch=='y'){
        int i=n, j=capacity;
        while(i>0){
            if(dp[i][j] == dp[i-1][j]){
                i--;
            }else{
                cout<<"\nItem picked: "<<i << " Weight-"<<items[i-1].weight << " Profit-"<<items[i-1].profit;
                j = j-items[i-1].weight;
                i--;
            }
        }
    }

    return dp[n][capacity];
}

int main(){
    int n, capacity;
    cout << "Enter the count of items: ";
    cin >> n;
    cout << "Enter capacity of bag: ";
    cin >> capacity;

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

    int result = find_max_profit(items, capacity, n);
    cout << endl << endl << "Maximum profit: " <<result <<endl;

    return 0;
}