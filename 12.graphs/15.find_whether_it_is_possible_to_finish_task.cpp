// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	        
	    }
	    int count=0;
	    
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        for(auto x:adj[temp]){
	            indegree[x]--;
	            if(indegree[x]==0){
	                q.push(x);
	            }
	        }
	        count++;    // to keep track of nodes visited
	    }
	    return count==N;  //true if exactly each node is visited only once. 
	    

	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends