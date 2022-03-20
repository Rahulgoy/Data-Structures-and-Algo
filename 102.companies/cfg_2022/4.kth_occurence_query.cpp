#include <bits/stdc++.h>
using namespace std;

void kthOcuurence(int x,vector<int> arr, vector<int> query){
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]].push_back(i);
    }

    for(int i=0;i<query.size();i++){
        if(mp.find(x)!=mp.end()){
            if(mp[x].size()<query[i]) cout<<-1<<endl;
            else cout<<mp[x][query[i]-1]+1<<endl;
        }else cout<<-1<<endl;
    }
}

int main(){
    // int x=8;
    // vector<int> arr={1,2,20,8,8,1,2,5,8,0};
    // vector<int> query={100,2,1,3,4};
    // -1,5,4,9,-1

    int x=9;
    vector<int> arr={9,8,9,9};
    vector<int> query={7,3,7,6};
    kthOcuurence(x,arr,query);
return 0;
}