#include <bits/stdc++.h>
using namespace std;

string firstWord(string s){

    int n = s.length();
    unordered_map<string, int> mp;
    string t="";
    string ans="";
    for(int i=n-1;i>=0;i--){
        
        if(s[i]==' '){
            mp[t]++;
            if(mp[t]>1) ans=t;
            t="";
        }else{
            t=t+s[i];
        }
    }
    mp[t]++;
    if(mp[t]>1) ans=t;
    t="";
    if(ans!=""){
        reverse(ans.begin(),ans.end());
        return ans;

    } 
    return "No Repitition";
}

int main(){

    string s="he had had he";

    cout<<firstWord(s)<<endl;

    return 0;
}