// The basic concept is to keep track of parent of the nodes
// if neighbouring node is visited but is not the parent of current node then there is cycle. 
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    // adj[v].push_back(u);
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


void topoSortDFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st){
    
    visited[node]=true;
    
    for(auto edge:adj[node]){
        if(!visited[edge]){
            topoSortDFS(edge,adj,visited,st);
        }
    }
    st.push(node);
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
    stack<int> st;
    for(int i=0;i<m;i++){
        if(!visited[i])
            topoSortDFS(i,adj,visited,st);
        }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;


return 0;
}