// Shortest path from source node to each node in direacted acyclic graph 
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v,int w, vector<pair<int,int>> adj[]){
    adj[u].push_back(make_pair(v,w));
}

void printGraph(vector<pair<int,int>> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(auto edge:adj[i]){
            cout<<edge.first<<" ";
        }
        cout<<endl;
    }
}

void topoArray(int node, vector<pair<int,int>> adj[], vector<bool> &visited, stack<int> &st){
    
    visited[node]=true;
    
    for(auto edge:adj[node]){
        if(!visited[edge.first]){
            // parent[edge]=node;
            topoArray(edge.first,adj,visited,st);
            }
    }
    st.push(node);
}

int main(){

    int m,n;
    cin>>m>>n;
    vector<pair<int,int>> adj[m];

    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w,adj);
    }
    // printGraph(adj,m);

    // Detect Cycle using BFS and DFS approach
    vector<bool> visited(m,false);
    stack<int> st;

    for(int i=0;i<m;i++){
        if(!visited[i]){
            topoArray(i,adj,visited,st);
        }
    }

    int src=1;
    vector<int> dist(m,INT_MAX);
    dist[src]=0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                // update the value of dist array say if start+neighbour<infinity then inifinity is replaced by start+neighbour
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }

    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}

// Sample Input with src=1
// 6 9
// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2

// Sample Output
// INT_MAX 0 2 6 5 3