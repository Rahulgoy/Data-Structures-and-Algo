#include <bits/stdc++.h>
using namespace std;

string findSubString(string str)
    {
        // Your code goes here   
        // Your code goes here   
    int n = str.length();
    set <char> s(begin(str), end(str));
    int no_of_dis_char = s.size();

    unordered_map<char,int> m;
    int j=1,i=0;
    m[str[i]]++;
    int count=0;
    count++;
    int ans = INT_MAX;
    int start=0,end=0;
    while(i<=j and j<n){
        if(count<no_of_dis_char){
            if(m[str[j]]==0) count++;
            m[str[j]]++;
            j++;
        }else if(count==no_of_dis_char){
            ans = min(ans,j-i);
            start = i;
            end = j-i;
            if(m[str[i]]==1) count--;
            m[str[i]]--;
            i++;
        }
    }
    while(count==no_of_dis_char){
        ans= min(ans,j-i);
        start = i;
        end = j-i;
        if(m[str[i]]==1) count--;
        m[str[i]]--;
        i++;
    }
    return str.substr(start,ans);
}

int main(){

    string s="AABBBCBBAC";

    cout<<findSubString(s)<<endl;

    return 0;
}

// O(N) time and space complexity