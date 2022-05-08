// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
int graphColoring(bool graph[101][101], int n)
{
    // your code here
    vector<int> res(n,-1);
    vector<bool> available(n,false);

    int cn = 0;
    for(int i=1;i<n;i++){
        for(auto x:graph[i]){
            if(res[x]!=-1) available[res[x]]=true;
        }

        int cr;
        for(cr=0;cr<n;cr++){
            if(available[cr]==false) break;
        }
        res[i]=cr;
        cn=max(cn,cr+1);

        for(auto x:graph[i]){
            if(res[x]!=-1) available[res[x]]=false;
        }
    }
    return cn;


}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n  >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends