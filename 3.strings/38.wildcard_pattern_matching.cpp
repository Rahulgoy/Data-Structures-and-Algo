#include <bits/stdc++.h>
using namespace std;

/* 
Wildcards allowed
* - can be replaced with 0 or 1 or many characters.
? - can be replaced with only one character.
 */
int dp[1001][1001];
int solve(string pattern, string s, int i,int j){
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    if(i==-1 and j==-1) return 1;
    if(j==-1){
        for(int k=0;k<i;k++){
            if(pattern[k]!='*') return 0;
        }
        return 1;
    }
    if(i==-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(pattern[i]==s[j] or pattern[i]=='?') return dp[i][j]=solve(pattern,s,i-1,j-1);
    if(pattern[i]=='*'){
        int a = solve(pattern,s,i-1,j);
        int b = solve(pattern,s,i,j-1);

        return dp[i][j] = a or b;
    }
    return dp[i][j]=0;  //when both characters doesn't match
}


int main(){
    string pattern="abcd?**";
    string s="adcdgaa";
    memset(dp,-1,sizeof(dp));

    // cout<<pattern<<" "<<s<<" "<<pattern.length()<<" "<<s.length()<<endl; 

    // cout<<solve(pattern,s,pattern.length()-1,s.length()-1)<<endl;
    solve(pattern,s,pattern.length()-1,s.length()-1) ? cout<<"True"<<endl:cout<<"false"<<endl; 

return 0;
}

// O(nm) time and space complexity