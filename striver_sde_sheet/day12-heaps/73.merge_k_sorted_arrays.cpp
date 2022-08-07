#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    // Method 1 Brute Force
//     vector<int> res;
//     for(int i=0;i<kArrays.size();i++){
//         for(int j=0;j<kArrays[i].size();j++){
//             res.push_back(kArrays[i][j]);
//         }
//     }
//     sort(res.begin(),res.end());
//     return res;
    
//     Method 2
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],i});
    }
    
    vector<int> res;
    vector<int> idx(k,0);
    while(!pq.empty()){
        pair<int,int> temp=pq.top();
        pq.pop();
        int i=temp.second;
        res.push_back(temp.first);
        if(idx[i]+1<kArrays[i].size())
            pq.push({kArrays[i][idx[i]+1],i});
        
        idx[i]+=1;
    }
    return res;
}
