// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j, vector<vector<bool>>& vis,vector<vector<char>>& grid,int m,int n){
        if(i<0 or j<0 or i>m-1 or j>n-1) return;
        if(vis[i][j] or grid[i][j]=='0') return;
        
        vis[i][j]=true;
        
        dfs(i+1,j,vis,grid,m,n);
        dfs(i-1,j,vis,grid,m,n);
        dfs(i,j+1,vis,grid,m,n);
        dfs(i,j-1,vis,grid,m,n);
        dfs(i+1,j+1,vis,grid,m,n);
        dfs(i-1,j-1,vis,grid,m,n);
        dfs(i+1,j-1,vis,grid,m,n);
        dfs(i-1,j+1,vis,grid,m,n);
        
        
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<grid[i].size();j++){
                if(vis[i][j]==false and grid[i][j]=='1'){
                    dfs(i,j,vis,grid,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends

/* 
Using DFS
Create a visited array
Iterate through grid for each i&j 
if not visited call dfs
return the count for how many times the dfs call is made

 */