#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int src,vector<int> &v1,vector<int> adj[],int v){
        queue<int> q;
        vector<int> vis(v+1);
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            v1.push_back(node);
            for(auto x:adj[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v1;
        bfs(0,v1,adj,V);
        return v1;
    }
};
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 