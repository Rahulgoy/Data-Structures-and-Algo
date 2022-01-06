#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        int mi = INT_MAX;
        string c = strs[0];
        
        for(int i=1;i<strs.size();i++){
            int ans=0,j=0,k=0;
            
            while(j<c.size() and k<strs[i].size()){
                if(c[j]==strs[i][k]) ans++;
                else break;
                j++;k++;
            }
            mi = min(mi,ans);
        }
        
        return c.substr(0,mi);
        
    }

int main(){

    string s1="flower",s2="flow",s3="flight";
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    cout<<longestCommonPrefix(v)<<endl;
return 0;
}