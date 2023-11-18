#include <bits/stdc++.h>
using namespace std;

#define Inf INT_MAX

class Node{
public:
    int vertex;
    int cost;
    vector<vector<int>> graph;
    Node(){

    }
    Node(int v, vector<vector<int>> g){
        this->vertex = v;
        this->graph = g;
    }
    
    int calcCost(int r, int c){
        int n = this->graph.size();
        // the logic of updating the graph values to Inf whenever we want the row and column reduction
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                if(i==r || j==c) graph[i][j] = Inf;
            }
        }
        graph[c][r] = Inf;
        int cost = 0;
        
        // for maintaing the row and column mimimum values
        vector<int> row = vector<int>(n, 0);
        vector<int> col = vector<int>(n, 0);
        
        cout << "\n\nCalculation for vertex: "<<c<<"\n";
        cout << "Minimum row wise: ";
        
        // trying to find the minimum values row wise
        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<n; j++) mini = min(graph[i][j], mini);
            // if the minimum was inf then updating it to zero
            if(mini == Inf) mini = 0;
            row[i] = mini;
            cout << mini << " ";
            cost += mini;
            // reducing the row now based on the minimum value found 
            for(int j=0; j<n; j++) if(graph[i][j]!=0 && graph[i][j]!=Inf) graph[i][j] -= mini; 
        }
        // trying to find the minimum values column wise
        cout << "\nMinimum column wise: ";
        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<n; j++) mini = min(graph[j][i], mini);
            if(mini == Inf) mini = 0;
            cout << mini << " ";
            col[i] = mini;
            cost += mini;
            // reducing the column now based on the minimum value found 
            for(int j=0; j<n; j++) if(graph[j][i]!=0 && graph[j][i]!=Inf) graph[j][i] -= mini;
        }
        return cost;
    }
};


int main(){

    vector<vector<int>> graph =  {
        { Inf, 20, 30, 10,11 },
        { 15, Inf, 16, 4, 2 },
        { 3, 5, Inf, 2, 4 },
        { 19, 6, 18, Inf, 3 },
        { 16, 4, 7, 16, Inf }
    };

    // initializing root node
    Node root(0, graph);
    // calculating cost for root node by passing -1, -1 
    int totalCost = root.calcCost(-1, -1);
    cout << "\nRoot node cost: " << totalCost<<"\n";
    
    int c=1;
    int n=graph.size();
    Node last = root;
    // maintaing visited array
    vector<int> visited(graph.size(), 0);
    visited[0] = 1;

    // sequence of visit
    vector<int> seq;

    while(c<n){
        // trying to find the minimum node which can be expanded
        int mini=INT_MAX;
        Node minNode;
        int Index;
        for(int i=1; i<n; i++){
            if(visited[i] == 1) continue; // if already dead dont visit it
            // creating a node with vertex number and passing the parent graph to it
            Node n(i, last.graph);
            // cost calculation = row col cost + the edge cost from parent to current vertex
            int cost = n.calcCost(last.vertex, i) + last.graph[last.vertex][i];
            if(mini> cost){
                mini = cost;
                minNode = n;
                Index = i;
            }
            cout << "\nCost: " <<totalCost+cost;
        }
        // updating the total cost
        totalCost+=mini;
        last = minNode;
        visited[last.vertex] = 1;
        c++;
        seq.push_back(last.vertex);
        cout << "\n\nMinimum found is " << totalCost;
        cout << "\n\n\n";
    }
    cout << "\nThe sequence found is: 0";
    for(auto s : seq){
        cout << " -> " <<s;
    }
    cout << "\nThe total cost is: "<<totalCost;


    return 0;
}
