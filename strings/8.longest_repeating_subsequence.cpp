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