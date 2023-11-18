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
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                if(i==r || j==c) graph[i][j] = Inf;
            }
        }
        int cost = 0;
        vector<int> row = vector<int>(n, 0);
        vector<int> col = vector<int>(n, 0);
        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<n; j++) mini = min(graph[i][j], mini);
            row[i] = mini;
            cout << mini << endl;
            cost += mini;
            for(int j=0; j<n; j++) if(graph[i][j]!=0 || graph[i][j]!=Inf) graph[i][j] -= mini;
        }

        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<n; j++) mini = min(graph[j][i], mini);
            col[i] = mini;
            cost += mini;
            for(int j=0; j<n; j++) if(graph[j][i]!=0 || graph[j][i]!=Inf) graph[j][i] -= mini;
        }
        return cost;
    }
};


int main(){

    vector<vector<int>> graph = {
        {Inf, 10, 15, 20},
        {5, Inf, 9, 10},
        {6, 13, Inf, 13},
        {8, 8, 9, Inf}
    };

    Node root(1, graph);

    cout << root.calcCost(-1, -1);
   
    int c=1;
    int n=graph.size();
    Node last = root;
    while(c<n){
        int mini=INT_MAX;
        Node minNode;
        int Index;
        for(int i=1; i<n; i++){
            int v = i+(c*n);
            Node n(v, last.graph);
            int cost = n.calcCost(0, i);
            if(mini> cost){
                mini = cost;
                minNode = n;
                Index = i;
                cout << cost;
            }
            
        }
        break;
    }


    return 0;
}
