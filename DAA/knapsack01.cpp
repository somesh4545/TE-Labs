#include<bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int profit;
};

int find_max_profit(item items[], int capacity, int n){
    char ch;
    cout << "Do you want to view whch items are picked(y/n): ";
    cin >> ch;

    int result = 0;

    int dp[n+1][capacity+1];

    // setting row1 and column1 as zero
    for(int i=0; i<capacity+1; i++) dp[0][i] = 0;
    for(int i=0; i<n+1; i++) dp[i][0] = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<capacity+1; j++){
            if(items[i-1].weight > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(items[i-1].profit+dp[i-1][j-items[i-1].weight], dp[i-1][j]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout <<  endl;
    }

    if(ch=='y'){
        int i=n, j=capacity;
        while(i>0){
            if(dp[i][j] == dp[i-1][j]){
                i--;
            }else{
                cout<<"\nItem picked: "<<i;
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