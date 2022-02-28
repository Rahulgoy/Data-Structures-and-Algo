#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
    
int solve(string s,string t,int m,int n){
    if(m==-1) return n+1;
    if(n==-1) return m+1;
    
    if(dp[m][n]!=-1) return dp[m][n];
    if(s[m]==t[n]) return dp[m][n]=solve(s,t,m-1,n-1);
    
    int a = solve(s,t,m,n-1);  //for insert operation
    int b = solve(s,t,m-1,n);  // for remove operation
    int c = solve(s,t,m-1,n-1); // for replcae operation
    
    return dp[m][n] = 1 + min(a, min(b,c));
}
    
    
int editDistance(string s, string t) {
    // Code here
    memset(dp,-1,sizeof(dp));
    int m = s.length();
    int n = t.length();
    return solve(s,t,m-1,n-1);
}

int main(){

    string s="geek";
    string t="gesek";

    cout<<editDistance(s,t);

    return 0;
}

// Time complexity O(s*t) space is same 