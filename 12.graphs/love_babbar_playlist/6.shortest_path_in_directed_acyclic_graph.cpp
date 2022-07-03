// We can't just keep track of parents in directed graph
// keep a new vector dfsCall 
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
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

bool detectCycleDFS(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsCall){
    
    visited[node]=true;
    dfsCall[node]=true;
    for(auto edge:adj[node]){
        if(!visited[edge]){
            // parent[edge]=node;
            if(detectCycleDFS(edge,adj,visited,dfsCall)) return true;
        }else if(dfsCall[edge]) return true;
    }
    dfsCall[node]=false;
    return false;
}

int main(){

    int m,n;
    cin>>m>>n;
    vector<int> adj[m];

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v,adj);
    }
    // printGraph(adj,m);

    // Detect Cycle using BFS and DFS approach
    vector<bool> visited(m,false);
    vector<bool> dfsCall(m,false);

    for(int i=0;i<m;i++){
        if(!visited[i]){
            if(detectCycleDFS(i,adj,visited,dfsCall)){
                cout<<"There is Cycle"<<endl;
                break;
            }
        }
    }


return 0;
}