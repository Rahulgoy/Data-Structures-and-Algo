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

bool bipartiteBFS(int node, vector<int> adj[], vector<int> &color){
    queue<int> q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto i:adj[frontNode]){
            if(!color[i]==-1){
                q.push(i);
                color[i]=1-color[frontNode];
            }else if(color[i]==color[frontNode]) return false;
        }
    }
    return true;
}

bool bipartiteDFS(int node, vector<int> adj[],  vector<int> &color){
    
    if(color[node]==-1) color[node]=1;
    
    for(auto edge:adj[node]){
        if(color[node]==-1){
            color[edge]=1-color[node];
            if(!bipartiteDFS(edge,adj,color)) return false;
        }else if(color[edge]==color[node]) return false;
    }
    return true;
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
    int flag=1;
    vector<int> color(m,-1);
    for(int i=0;i<m;i++){
        if(color[i]==-1){
            if(!bipartiteBFS(i,adj,color)){
                flag=0;
            }
        }
    }
    
    if(flag) cout<<"It is bipartite"<<endl;


return 0;
}

// Input 1: with output: yes
// 10 10
// 0 1
// 1 2
// 2 3
// 2 5
// 3 4
// 5 6
// 6 7
// 4 7
// 7 8
// 8 9

// Input with ans:No
// 10 10
// 0 1
// 1 2
// 2 3
// 2 5
// 3 4
// 5 6
// 6 7
// 4 6
// 7 8
// 8 9
