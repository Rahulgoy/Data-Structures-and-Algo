#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    map<int,int> mp;
    for(auto num:arr){
        mp[num]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
    }
    
    vector<int> res;
    while(k--){
        pair<int,int> temp=pq.top();
        pq.pop();
        res.push_back(temp.second);
    }
    sort(res.begin(),res.end());
    return res;
}