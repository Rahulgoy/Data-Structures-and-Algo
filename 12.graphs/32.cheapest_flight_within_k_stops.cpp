#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto flight:flights){
            g[flight[0]].push_back({flight[1],flight[2]});
        }
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push(make_tuple(0,src,0));
        while(!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(u==dst) return cost;
            if(stops>k) continue;
            else{
                for(auto child:g[u]){
                auto [v,w] = child;
                pq.push(make_tuple(cost+w,v,stops+1));
            }
            }
            
        }
        return -1;
    }

int main(){


return 0;
}