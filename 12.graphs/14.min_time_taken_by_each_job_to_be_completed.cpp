/* 
Calculate the indegree of all the vertexes
Then decrease the indegrees one by one if indegree==0 then add that time.
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

    int V,E;
    cin>>V>>E;
    vector<int> adj[V+1];
    vector<int> indegree(V+1,0);
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    vector<int> res(V+1,0);
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
            res[i]=1;
        }
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto x:adj[temp]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
                res[x]=res[temp]+1;
            }
        }
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

return 0;
}

/* 
Sample Input
10 13
1 3
1 4
1 5
2 3
2 8
2 9
3 6
4 6
4 8
5 8
6 7
7 8
8 10

Ouptut
1122234526
 */