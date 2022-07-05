#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(auto edge:adj[i]){
            cout<<edge<<" ";
        }
        cout<<endl;
    }
}



void shortestPathDFS(int node,int parent,int &timer,vector<int> &disc, vector<int> &low,vector<int> adj[], vector<bool> &visited){
    
    visited[node]=true;
    disc[node]=low[node]=timer++;

    for(auto edge:adj[node]){
        if(edge==parent) continue;
        if(!visited[edge]){
            shortestPathDFS(edge,node,timer,disc,low,adj,visited);
            low[node] = min(low[node],low[edge]); // if there is a backedge update the low of node with neigbour

            if(low[edge]>disc[node]){ // means there is no other way to discover the node except the current edge hence it can be bridge.
                cout<<node<<" "<<edge<<endl;
            }
        }else{
            low[node]=min(low[node],disc[edge]);
        }
    }
  
}

int main(){

    int m,n;
    cin>>m>>n;
    
    int parent,timer=0;

    vector<int> adj[m];

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v,adj);
    }
    // printGraph(adj,m);

    // Detect Cycle using BFS and DFS approach
    vector<bool> visited(m,false);
    vector<int> low(m,-1);
    vector<int> disc(m,-1);
    
    shortestPathDFS(0,-1,timer,disc,low,adj,visited);


return 0;
}

// 
// 5 5
// 0 1
// 1 2
// 0 2
// 0 3
// 3 4

// Output
// 3 4
// 0 3