#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    // Method 1
    // O(n^2) time complexity
//     int m=a.size();
//     int o=b.size();
//     priority_queue<int> pq;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<o;j++){
//             pq.push(a[i]+b[j]);
//         }
//     }
//     set<int> s;
    
//     while(s.size()!=k){
//         s.insert(pq.top());
//         pq.top();
//     }
//     vector<int>res(s.begin(),s.end());
//     return res;
    
//     Method 2
    priority_queue<pair<int,pair<int,int>>> pq;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    set<pair<int,int>> s;
    pq.push(make_pair(a[n-1]+b[n-1], make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    vector<int> res;
    for(int count=0;count<k;k++){
        pair<int,pair<int,int>> temp = pq.top();
        pq.top();
        res.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        
        int sum=a[i-1]+b[j];
        if(s.find(make_pair(i-1,j))==s.end()){
            pq.push(make_pair(sum,make_pair(i-1,j)));
            s.insert(make_pair(i-1,j));
        }
        
        sum=a[i]+b[j-1];
        if(s.find(make_pair(i,j-1))==s.end()){
            pq.push(make_pair(sum,make_pair(i,j-1)));
            s.insert(make_pair(i,j-1));
        }
        
    }
    return res;
    
}