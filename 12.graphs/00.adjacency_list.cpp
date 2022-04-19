#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>>res;
        for(int i=0;i<V;i++){
            vector<int> temp = adj[i];
            // temp.push_front(i);
            temp.insert(temp.begin(), i);
            res.push_back(temp);
        }
        
        return res;
    }

int main(){


return 0;
}