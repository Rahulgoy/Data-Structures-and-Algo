//  https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

vector<int> vis,col;
    
    bool dfs(int i,int color,vector<vector<int>> &graph){
        vis[i]=1;
        col[i]=color;
        
        for(auto x:graph[i]){
            if(vis[x]==0){
                if(!dfs(x,color^1,graph)) return false;
            }else{
                if(col[i]==col[x]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n);
        col.resize(n);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0 and dfs(i,0,graph)==false) return false;
        }
        return true;
    }

int main(){


return 0;
}

/* 
A graph is bipartite if the nodes can be partitioned 
into two independent sets A and B such that every edge
in the graph connects a node in set A and a node in set
B.

Basic Idea is to use graph coloring. If the graph can be 
colored in only two colors then it is bipartite.
To do so we have take care of vertexes that create odd
number of circle.
So if there is odd circle then it is not bipartite
if even vertex circle it is.

Sample Input:
[[1,2,3],[0,2],[0,1,3],[0,2]]
Output:
False

 */