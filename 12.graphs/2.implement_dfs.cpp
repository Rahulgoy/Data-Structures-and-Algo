#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void dfs(int src,vector<int> &v1,vector<int> adj[],int v){
        stack<int> q;
        vector<int> vis(v+1);
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node = q.top();
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
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v1;
        dfs(2,v1,adj,V);
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 

/* 
Sample Input
1
4 6
0 1
0 2
1 2
1 3
2 0
3 3 
*/