// Prims Algo for minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

// void addEdge(int u, int v,int w, vector<pair<int,pair<int,int>>> adj){
//     adj.push_back({w,{u,v}});
    
// }

// void printGraph(vector<pair<int,pair<int,int>>> adj,int v){
//     for(int i=0;i<v;i++){
//         cout<<i<<"->";
//         for(auto edge:adj){
//             cout<<"["<<edge.first<<" "<<edge.second<<"]"<<" ";
//         }
//         cout<<endl;
//     }
// }

int findParent(vector<int> &parent, int node){
    if(parent[node]==node)
        return node;
    return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int>&rank){
    int p_u = findParent(parent,u);
    int p_v = findParent(parent,v);

    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[u]>rank[v])
        parent[v]=u;
    else{
        parent[u]=v;
        rank[v]++;
    }
}


int main(){

    int m,n;
    cin>>m>>n;

    // vector<pair<int,pair<int,int>>> adj;
    vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // addEdge(u,v,w,adj);
        adj.push_back({u,v,w});
    }
    // printGraph(adj,m);

    int src=0;
    vector<int> rank(m,0);
    vector<int> parent(m);
    for(int i=0;i<m;i++){
        parent[i]=i;
    }

    int minWgt=0;

    for(auto i:adj){
        // cout<<"Hello";
        int u=findParent(parent,i[0]);
        int v=findParent(parent,i[1]);
        // cout<<u<<":"<<v<<endl;
        if(u!=v){
            minWgt+=i[2];
            unionSet(u,v,parent,rank);
        }
    }
    cout<<minWgt<<endl;

return 0;


}

// 5 6
// 0 1 2
// 1 2 3
// 0 3 6
// 3 1 8
// 1 4 5
// 4 2 7
// Output
//  0 5 8 7