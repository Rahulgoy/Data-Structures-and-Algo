// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1000][1000];
    
    int func(int x, int y, string s1, string s2){
        if(x==-1 or y==-1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        
        if(s1[x]==s2[y]) return dp[x][y] = 1 + func(x-1,y-1,s1,s2);
        
        int a = func(x-1,y,s1,s2);
        int b = func(x,y-1,s1,s2);
        
        return dp[x][y] = max(a,b);
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return func(x-1,y-1,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends


/* Input
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR

Output
3
*/