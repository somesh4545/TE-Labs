#include<bits/stdc++.h>
using namespace std;

int main(){
    // taking number of vertices and edges count from user
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    int n_edges;
    cout << "Enter count of edges: ";
    cin >> n_edges;

    // declaring the edges vector and taking input from user
    vector<vector<int>> edges(n_edges, (vector<int>(3, 0)));
    cout << "From to weight: (enter in this format)\n";
    for(int i=0; i<n_edges; i++){
        cout << (i+1) << " edge: ";
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; 
    }

    // declaring dist array and intialzing the distance of source as 0
    int dist[V];
    for(int i=0; i<V; i++) dist[i] = INT_MAX;
    dist[0] = 0;
   
    // calculating shortest path from 0 to all the vertices
    for(int i=0; i<V-1; i++){
        for(int j=0; j<n_edges; j++){
            int u = edges[j][0]-1, v=edges[j][1]-1;
            int weight = edges[j][2];

            if(dist[u]!=INT_MAX && dist[u]+weight < dist[v]){
                dist[v] = dist[u]+weight;
            }
        }
    }

    // checking once again to find if negative edge cycle is present or not
    for(int i=0; i<V-1; i++){
        bool flag = true;
        for(int j=0; j<n_edges; j++){
            int u = edges[j][0]-1, v=edges[j][1]-1;
            int weight = edges[j][2];
            if(dist[u]!=INT_MAX && dist[u]+weight < dist[v]){
                cout << "\n\nNegative edge cycle is present\n";
                flag = false;
                break;
            }    
        }
        if(!flag) break;
    }
    cout << endl << endl;

    cout << "Vertex\tDistance from source\n";

    for(int i=0; i<V; i++){
        cout << i << "\t" <<dist[i] << "\n";
    }

    return 0;
}