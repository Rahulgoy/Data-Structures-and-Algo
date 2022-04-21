// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j, vector<vector<int>> &m, int n,vector<vector<bool>> &vis, vector<string> &res,string s){
        if(i==n-1 and j==n-1){
            res.push_back(s);
            return;
        } 
        if(i<0 or j<0 or i>n-1 or j>n-1) return;
        if(vis[i][j]==true or m[i][j]==0) return;
        
        vis[i][j]=true;
        
        solve(i+1,j,m,n,vis,res,s+"D");
        solve(i,j+1,m,n,vis,res,s+"R");
        solve(i-1,j,m,n,vis,res,s+"U");
        solve(i,j-1,m,n,vis,res,s+"L");
        vis[i][j]=false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return res;
        }
        solve(0,0,m,n,vis,res,"");
        return res;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends