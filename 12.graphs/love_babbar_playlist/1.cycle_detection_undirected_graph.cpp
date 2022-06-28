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

bool detectCycleBFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent){
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
            }else if(i!=parent[frontNode]) return true;
        }
    }
    return false;
}

bool detectCycleDFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent){
    
    visited[node]=true;
    
    for(auto edge:adj[node]){
        if(!visited[edge]){
            parent[edge]=node;
            detectCycleDFS(edge,adj,visited,parent);
        }else if(edge!=parent[node]) return true;
    }
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
    vector<int> parent(m);
    for(int i=0;i<m;i++){
        if(!visited[i]){
            if(detectCycleDFS(i,adj,visited,parent)){
                cout<<"There is Cycle"<<endl;
                break;
            }
        }
    }


return 0;
}