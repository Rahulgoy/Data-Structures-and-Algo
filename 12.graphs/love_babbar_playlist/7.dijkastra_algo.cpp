// Shortest distance from source node to each node in undirected graph
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
    // printGraph(adj,m);

    int src=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(m,INT_MAX);
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int frontNode=pq.top().second;
        int frontDist=pq.top().first;
        pq.pop();
        // cout<<" front:"<<frontNode;
        for(auto nbr:adj[frontNode]){
            // this is data being accessed from adjacency list where node is first then weight
            int nextNode=nbr.first;
            int nextDist=nbr.second;

            if(frontDist+nextDist<dist[nextNode]){
                dist[nextNode]=frontDist+nextDist;
                pq.push(make_pair(dist[nextNode],nextNode));
            }
        }
    }
    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}

// 4 5
// 0 1 5
// 0 2 8
// 1 3 2
// 2 3 6
// 1 2 9
// Output
//  0 5 8 7