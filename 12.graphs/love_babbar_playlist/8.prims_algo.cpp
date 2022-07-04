// Prims Algo for minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v,int w, vector<pair<int,int>> adj[]){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void printGraph(vector<pair<int,int>> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(auto edge:adj[i]){
            cout<<"["<<edge.first<<" "<<edge.second<<"]"<<" ";
        }
        cout<<endl;
    }
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
    printGraph(adj,m);

    int src=0;
    vector<int> key(m,INT_MAX);
    vector<int> parent(m,-1);
    vector<bool> mst(m,false);

    key[src]=0;
    parent[src]=-1;
    for(int i=0;i<m-1;i++){
        int minNode = INT_MAX;
        int parentNode;
        // cout<<parentNode<<endl;
        // cout<<parentNode<<" "<<minNode;
        for(int j=0;j<m;j++){
            if(mst[j]==false && key[j]<minNode){
                parentNode=j;
                minNode=key[j];
            } 
        }
        // cout<<parentNode<<" "<<minNode;
        mst[parentNode] = true;
        // cout<<"Hello"<<endl;
        for(auto it:adj[parentNode]){
            int nextNode = it.first;
            int nextWgt = it.second;
            if(mst[nextNode]==false && nextWgt<key[nextNode]){
                parent[nextNode]=parentNode;
                key[nextNode]=nextWgt;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for(int i=1;i<m;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    int cost=0;
    for(auto it:key)
        cost+=it;
    cout<<cost<<endl;

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