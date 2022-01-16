// Intersection and Union of sorted arrays

#include <bits/stdc++.h>
using namespace std;

int findUnion(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    set<int> s;     
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        s.insert(b[i]);
    }
    return s.size();

}

int findInter(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    unordered_map<int,int> mp;
        
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(int i=0;i<m;i++){
        mp[b[i]]++;
    }
    
    vector<int> res;
    for(auto x:mp){
        if(x.second>1) res.push_back(x.first);
    }
    return res.size();
}


int main(){

    vector<int> a = {1,3,6,7,9};
    vector<int> b = {1,2,3,4,5,6};

    cout<<findInter(a,b)<<endl;
    cout<<findUnion(a,b)<<endl;

return 0;
}