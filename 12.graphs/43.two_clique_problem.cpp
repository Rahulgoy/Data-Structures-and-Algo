#include <bits/stdc++.h>
using namespace std;

int f=0;
void bipartite(int src, int par, int col, vector<int>&color,vector<int> g[]){
    color[src] = col;
    for(auto x:g[src]){
        if(!color[x]){
            bipartite(x,src,col^1,color,g);
        }else if(x!=par and col==color[x]){
            f=1;
            break;
        }}
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> g[v];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> reverse[v];
    vector<int> dummy(v,0);
    for(int i=0;i<v;i++){
        dummy[i]=1;
        for(auto x:g[i]){
            dummy[x]=1;
        }
        for(int j=0;j<v;j++){
            if(dummy[j]==0){
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }

    vector<int> color(v,0);
    bipartite(0,0,1,color,reverse);
    if(!f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

return 0;
}


/* 
Basic Idea is:
Two clique problem is - if graph can be divided into two parts
such that every vertex in one part is connected to every vertex in other part.

To solve this problem the steps used are:
1. Reverse the adjacency list i.e if there are 0,1,2,3 vertices
   and 0-1, then reverse would be 0-2,3
2. Apply Bipartite Matching on the reversed graph
3. If it is bipartite then the graph is two clique


Sample Input:
5 5
0 1
1 2
2 0
0 3
3 4

Sample Output:
True
 */