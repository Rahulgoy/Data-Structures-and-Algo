#include <bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list) {
    //code here
    vector<vector<string> > ans;
    unordered_map<string, vector<string>> mp;
    
    int n = string_list.size();
    for(int i=0;i<n;i++){
        string temp = string_list[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(string_list[i]);
        
    }
    for(auto i:mp){
        ans.push_back(i.second);
        
    }
    
    return ans;
    
}

int main(){

    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<vector<string>> res;
    res = Anagrams(v);

return 0;
}