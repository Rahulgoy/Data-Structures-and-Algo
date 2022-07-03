// Kahns Algo using BFS to get toposort

// Same algo can also be used to detect cycle in directed graphs by just replacing count++ with ans.pushback
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


void topoSortKahn(vector<int> adj[], queue<int> &q, vector<int> &indegree, vector<int> &ans){
    
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto node:adj[frontNode]){
            indegree[node]--;
            if(indegree[node]==0) q.push(node);
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

    vector<int> indegree(m);
    queue<int> q;
    for(auto i:adj){
        for(auto j:i){
            indegree[j]++;
        }
    }

    // for(int i=0;i<indegree.size();i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0) {
            q.push(i);
            // cout<<i;
        }
    }

    vector<int> ans;
    // topoSortKahn(adj,q,indegree,ans);
    int count =0;

    while(!q.empty()){
        int frontNode=q.front();
        cout<<frontNode<<" ";
        q.pop();
        ans.push_back(frontNode);
        count++;

        for(auto node:adj[frontNode]){
            indegree[node]--;
            if(indegree[node]==0) q.push(node);
        }
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }        
    cout<<endl;
    
    if(count==m){
        cout<<"There is no cycle";
    }else cout<<"There is cycle";
    


return 0;
}

// Sample Input
// 6 7
// 0 1
// 0 2
// 1 3
// 2 3
// 3 4
// 3 5
// 4 5
// Output
// 0 1 2 3 4 5 or 0 2 1 3 4 5 