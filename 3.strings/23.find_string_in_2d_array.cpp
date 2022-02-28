// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};   //For all eight directions
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool solve(vector<vector<char>>arr, string s, int n, int m, int i, int j){
        for(int dir=0; dir<8; dir++){
           int x=i+dx[dir];
           int y=j+dy[dir];
           int idx;
           for(idx=1;idx<s.length();idx++){
               if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] != s[idx]) break;
               x += dx[dir];
               y += dy[dir];
           }
           if(idx==s.length()) return true;
       }
       return false;
   }



	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int size = word.length();
	    int l = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> res;
	    for(int i=0;i<l;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                if(solve(grid,word,l,m,i,j)) res.push_back({i,j});
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends


/*Sample input
1
3 4
abab
abeb
ebeb
abe

Sample output

0 0 
0 2 
1 0

*/


/* 
The main diference between this question and the previous one i.e 22 is:
1. Rather than count we have to print the starting index
2. We cannot move in zig-zag direction.
3. We have to move in a single direction( i.e among all 8)
 */