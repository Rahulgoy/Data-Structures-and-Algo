#include <bits/stdc++.h>
using namespace std;

string smallestWindow (string str, string p)
    {
        // Your code here
        int n = str.length();
        int p_len = p.length();
        
        
        if(n<p_len) return "-1";
        
        int no_of_dis_char = p.length();
        unordered_map<char,int> m;
        for(auto it:p){
            m[it]=0;
        }
        
        
        int j=1,i=0;
        int count=0;
        if(p.find(str[0])!=string::npos){
                    count++;
                    m[str[0]]++;
        }
        int ans = INT_MAX;
        int start=0,end=0;
        
        while(i<=j and j<n){
            if(count<no_of_dis_char){
                if(p.find(str[j])!=string::npos){
                    if(m[str[j]]==0) count++;
                    m[str[j]]++;
                }
                j++;
            }else if(count==no_of_dis_char){
                ans = min(ans,j-i);
                start = i;
                if(p.find(str[i])!=string::npos){
                    if(m[str[i]]==1) count--;
                    m[str[i]]--;
                }
                i++;
            }
        }
        while(count==no_of_dis_char){
            ans= min(ans,j-i);
            start = i;
            if(p.find(str[i])!=string::npos){
                    if(m[str[i]]==1) count--;
                    m[str[i]]--;
            }
            i++;
        }
        return str.substr(start,ans);
        }

int main(){


return 0;
}