#include <bits/stdc++.h>
using namespace std;


// default int value in map is 0
// substr(starting index, distance) ex substr(1,3) means start from one and move to 1+3=4


unordered_map<string,int> dp;
int solve(string s,vector<string> &b){
    int l = s.length();
    if(l==0) return 1;
    
    if(dp[s]!=0) return dp[s];
    
    for(int i=1;i<=l;i++){
        int flag=0;
        string sub = s.substr(0,i);
        for(int j=0;j<b.size();j++){
            if(sub.compare(b[j])==0){
                flag=1;
                break;
            }
        }
        if(flag==1 and solve(s.substr(i,l-i),b)==1) return dp[s]=1;
        
    }
    return dp[s]=-1;
    
    
}
int wordBreak(string A, vector<string> &B) {
    //code here
    int ans = solve(A,B);
    if(ans==1) return 1;
    else return 0;
}


int main(){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";

return 0;
}

// Sample Input
/*
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
*/
