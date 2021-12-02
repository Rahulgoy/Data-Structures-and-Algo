// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> v;
    
    void dfs(int x, int y,string s,vector<vector<int>> &m, int n, vector<vector<int>> &visited){
        if(x<0 or y<0 or x>=n or y>=n) return;
        if(m[x][y]==0 or visited[x][y]==1) return;
        if(x==n-1 and y==n-1){
            v.push_back(s);
            return;
        }
        visited[x][y]=1;
        dfs(x+1,y,s+'D',m,n,visited);
        dfs(x,y+1,s+'R',m,n,visited);
        dfs(x-1,y,s+'U',m,n,visited);
        dfs(x,y-1,s+'L',m,n,visited);
        visited[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        v.clear();
        if(m[n-1][n-1]==0) return v;
        if(m[0][0]==0) return v;
        vector<vector<int>> visited(n+1, vector<int>(n));
        dfs(0,0,s,m,n,visited);
        sort(v.begin(),v.end());
        return v;
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
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends