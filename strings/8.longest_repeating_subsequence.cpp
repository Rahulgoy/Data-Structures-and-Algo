// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
		    // Code here
	int n = str.length();
	int dp[n+1][n+1];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 or j==0){
				dp[i][j]=0;
				
			}
			else if(str[i-1]==str[j-1] and i!=j) dp[i][j] = dp[i-1][j-1] + 1;
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}


int main(){

string s = "axxxy";
cout<<LongestRepeatingSubsequence(s)<<endl;

return 0;
}








/* 
The same code for LCS

int dp[1001][1001];
    int func(int x,int y, string &s, string &t){
        if(x==-1 or y==-1) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        else{
            if(s[x]==t[y] and x!=y) return dp[x][y] = 1 + func(x-1,y-1,s,t);
            else{
                int a = func(x-1,y,s,t);
                int b = func(x,y-1,s,t);
                return dp[x][y] = max(a,b);
            }
        
        }
        
    }
    
    int LongestRepeatingSubsequence(string str){
        int x = str.length();
        
        
        memset(dp,-1,sizeof(dp));
        return func(x-1,x-1,str,str);
    }

 */