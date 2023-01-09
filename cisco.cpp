#include <bits/stdc++.h>
using namespace std;


int func(vector<int> InitialAsk){
    unordered_map<int,int> mp;
    queue<pair<int,int>> q;
    int result=0;
    for(int i=0;i<InitialAsk.size();i++){
        q.push({10,InitialAsk[i]});
    }
    while(!q.empty()){
        pair<int,int> top=q.front();
        q.pop();
        if(mp.find(top.second)!=mp.end()){
            // mp[top.second]++;
            result+=top.first;
            q.push({top.first*2,top.second+1});
        }else{
            mp[top.second]=top.first;
        }

    }
    return result;
}

int main(){

    vector<int> temp={1,1,2};
    cout<<func(temp)<<endl;
return 0;
}