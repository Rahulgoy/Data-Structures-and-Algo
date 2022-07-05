// detect number of strongly connected components
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

void topoOrder(int node, vector<int> adj[], vector<bool> &visited, stack<int>&s){
    
    visited[node]=true;
    for(auto edge:adj[node]){
        if(!visited[edge]){
            topoOrder(edge,adj,visited,s);
    }
    
    }
    s.push(node);
}

void revDFS(int node, vector<int> adj[], vector<bool> &visited){
    
    visited[node]=true;
    // cout<<node<<" ";
    for(auto edge:adj[node]){
        if(!visited[edge]){
            revDFS(edge,adj,visited);
    }
    }

    
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

    // Step 1 : Topological Ordering
    stack<int> s;
    for(int i=0;i<m;i++){
        if(!visited[i])
            topoOrder(i,adj,visited,s);

    }
    
    // Step 2: Transpose of graph
    vector<int> transposeAdj[m];
    for(int i=0;i<m;i++){
        visited[i]=false;
        for(auto it:adj[i]){
            transposeAdj[it].push_back(i);
        }
    }
    printGraph(transposeAdj,m);
    // Step 3: dfs call
    int count=0;
    while(!s.empty()){
        int topNode=s.top();

        s.pop();
        if(!visited[topNode]){
            count++;
            revDFS(topNode,transposeAdj,visited);
        }
    }
    cout<<count<<endl;


    return 0;
}

// Input
// 5 5
// 0 1
// 1 2
// 2 0
// 1 3
// 3 4

// Output:3