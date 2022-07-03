// The basic concept is to keep track of parent of the nodes
// if neighbouring node is visited but is not the parent of current node then there is cycle. 
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

void detectCycleBFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=frontNode;
            }
        }
    }
    // return false;
}

void shortestPathDFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent){
    
    visited[node]=true;
    
    for(auto edge:adj[node]){
        if(!visited[edge]){
            parent[edge]=node;
            shortestPathDFS(edge,adj,visited,parent);
        }
    }
  
}

int main(){

    int m,n;
    cin>>m>>n;
    int src,dest;
    cin>>src>>dest;
    vector<int> adj[m];

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v,adj);
    }
    // printGraph(adj,m);

    // Detect Cycle using BFS and DFS approach
    vector<bool> visited(m,false);
    vector<int> parent(m);
    vector<int> ans;
    parent[src]=-1;
    detectCycleBFS(src,adj,visited,parent);
    // for(auto p:parent){
    //     cout<<p<<" ";
    // }
    // cout<<endl;
    int currentNode=dest;
    ans.push_back(currentNode);
    while(currentNode!=src){
        
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
        
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}

// 
// 8 9
// 0 7
// 0 1
// 0 2
// 0 3
// 1 4
// 4 7
// 2 7
// 3 5
// 5 6
// 6 7