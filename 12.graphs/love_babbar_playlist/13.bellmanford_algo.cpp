// Shortest distance from source node to each node in undirected graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v,int w, vector<vector<int>> &adj){
    adj.push_back({u,v,w});
}





int main(){

    int m,n;
    cin>>m>>n;

    vector<vector<int>> adj;

    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w,adj);
    }
    // printGraph(adj,m);

    int src=0;
    
    vector<int> dist(m,INT_MAX);
    dist[src]=0;

    // Run loop for m-1 times
    for(int i=1;i<=m;i++){
        for(auto it:adj){
            int src=it[0];
            int dest=it[1];
            int wt=it[2];

            if(dist[src]!=INT_MAX && (dist[src]+wt<dist[dest])){
                dist[dest]=dist[src]+wt;
            }
        }
    }

    bool flag=false;
    for(auto it:adj){
            int src=it[0];
            int dest=it[1];
            int wt=it[2];

            if(dist[src]!=INT_MAX && (dist[src]+wt<dist[dest])){
                flag=true;
            }
        }
    if(flag) cout<<"Negative Cycle";
    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}

// 3 3
// 0 1 2
// 0 2 2
// 1 2 -1
// Output
//  0 2 1