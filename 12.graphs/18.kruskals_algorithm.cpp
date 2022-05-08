#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b] = a;
        sz[a]+=sz[b];
    }
}





void kruskal(vector<vector<int>> &adj,int V,int E){
    sort(adj.begin(),adj.end());
    int cost=0;
    for(auto edge:adj){
        int w=edge[0];
        int x=edge[1];
        int y=edge[2];

        if(find_set(x)==find_set(y)) continue;
        else{
            cout<<x<<" "<<y<<"\n";
            cost+=w;
            union_sets(x,y);

        }
    }
    cout<<cost;
}

int main(){

    for(int i=0;i<N;i++){
        make_set(i);
    }

    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj;


    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj.push_back({w,x,y});
    }

    kruskal(adj,V,E);
return 0;
}