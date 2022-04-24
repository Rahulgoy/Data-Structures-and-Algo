/* Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering 
of vertices such that for every directed edge u v, vertex u comes before v in 
the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG. */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoSortHelper(int i,vector<int> adj[], vector<bool> &vis, stack<int> &s){
	    vis[i]=true;
	    
	    for(auto x:adj[i]){
	        if(!vis[x]){
	            topoSortHelper(x,adj,vis,s);
	        }
	    }
	    s.push(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V,false);
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            topoSortHelper(i,adj,vis,s);
	        }
	    }
	    vector<int> res;
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends

/* 
Sample Input
1
3 4 
3 0
3 2
2 0


 */