// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    void solve(int i,int j, int a,int b, int n, int val,vector<vector<int>> &arr,vector<vector<int>> &vis){
        
        if(i<0 or j<0 or i>n-1 or j>n-1) return;
        if(vis[i][j]==1) return;
        // cout<<i<<" "<<j<<endl;
        arr[i][j]=val+1;
        vis[i][j]=1;
        solve(i+1,j+2,a,b,n,arr[i][j],arr,vis);
        solve(i-1,j+2,a,b,n,arr[i][j],arr,vis);
        solve(i+2,j+1,a,b,n,arr[i][j],arr,vis);
        solve(i-2,j+1,a,b,n,arr[i][j],arr,vis);
        solve(i-2,j-1,a,b,n,arr[i][j],arr,vis);
        solve(i+2,j-1,a,b,n,arr[i][j],arr,vis);
        solve(i+1,j-2,a,b,n,arr[i][j],arr,vis);
        solve(i-1,j-2,a,b,n,arr[i][j],arr,vis);
        vis[i][j]=0;
        
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1= KnightPos[0];
	    int x2= TargetPos[0];
	    int y1= KnightPos[1];
	    int y2= TargetPos[1];
	    
	    if(x1==x2 && y1==y2){
	        return 0; // already at the destination case
	    }

	    vector<vector<int>> arr(N,vector<int>(N,0));
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    solve(x1-1,y1-1,x2-1,y2-1,N,0,arr,vis);
	    
	    return arr[x2-1][y2-1];
	}
};
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1= KnightPos[0];
	    int x2= TargetPos[0];
	    int y1= KnightPos[1];
	    int y2= TargetPos[1];
	    
	    if(x1==x2 && y1==y2){
	        return 0; // already at the destination case
	    }

	    queue<pair<int,int>>q; // stores the position to visit next
	    q.push({x1-1,y1-1});
	    vector<vector<int>> visited(N,vector<int>(N,0)); // stores the visited or not visited
	    visited[x1-1][y1-1]=0;
	    
	    while(!q.empty()){
	        auto curr= q.front();
	        q.pop();
	        int i= curr.first;
	        int j= curr.second;
	        if(i-2>=0 && j-1>=0 && i-2<N && j-1<N && visited[i-2][j-1]==0){
	            visited[i-2][j-1]= 1+visited[i][j];
	            q.push({i-2,j-1});
	        }
	        if(i-2>=0 && j+1>=0 && i-2<N && j+1<N && visited[i-2][j+1]==0){
	            visited[i-2][j+1]= 1+visited[i][j];
	            q.push({i-2,j+1});
	        }
	        if(i-1>=0 && j+2>=0 && i-1<N && j+2<N && visited[i-1][j+2]==0){
	            visited[i-1][j+2]= 1+visited[i][j];
	            q.push({i-1,j+2});
	        }
	        if(i+1>=0 && j+2>=0 && i+1<N && j+2<N && visited[i+1][j+2]==0){
	            visited[i+1][j+2]= 1+visited[i][j];
	            q.push({i+1,j+2});
	        }
	        
	        if(i+2>=0 && j-1>=0 && i+2<N && j-1<N && visited[i+2][j-1]==0){
	            visited[i+2][j-1]= 1+visited[i][j];
	            q.push({i+2,j-1});
	        }
	        if(i+2>=0 && j+1>=0 && i+2<N && j+1<N && visited[i+2][j+1]==0){
	            visited[i+2][j+1]= 1+visited[i][j];
	            q.push({i+2,j+1});
	        }
	        if(i-1>=0 && j-2>=0 && i-1<N && j-2<N && visited[i-1][j-2]==0){
	            visited[i-1][j-2]= 1+visited[i][j];
	            q.push({i-1,j-2});
	        }
	        if(i+1>=0 && j-2>=0 && i+1<N && j-2<N && visited[i+1][j-2]==0){
	            visited[i+1][j-2]= 1+visited[i][j];
	            q.push({i+1,j-2});
	        }
	    }
	    return visited[x2-1][y2-1];
	}
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends