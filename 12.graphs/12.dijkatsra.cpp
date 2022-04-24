#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        s.insert({0,S});
        while(!s.empty()){
            pair<int,int> temp = *s.begin();
            s.erase(s.begin());
            for(auto node:adj[temp.second]){
                if(temp.first+node[1]<dist[node[0]]){
                    dist[node[0]]=temp.first+node[1];
                    s.insert({dist[node[0]],node[0]});
                }
            }
        }
        return dist;
    }

int main(){


return 0;
}