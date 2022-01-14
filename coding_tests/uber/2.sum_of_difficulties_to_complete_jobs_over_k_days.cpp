// https://www.tutorialspoint.com/program-to-find-minimum-sum-of-difficulties-to-complete-jobs-over-k-days-in-cplusplus

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
int dp[505][15];
int dfs(int start, int k, vector <int>& v){
   if(start >= v.size()){
      return k == 0 ? 0 : inf;
   }
   if(k < 0)
      return inf;
   if(dp[start][k] != -1)
      return dp[start][k];
   int ret = inf;
   int val = 0;
   for(int i = start; i < v.size(); i++){
      val = max(val, v[i]);
      ret = min(ret, val + dfs(i + 1, k - 1, v));
   }
   return dp[start][k] = ret;
}
int solve(vector<int>& jobs, int k) {
   memset(dp ,-1, sizeof dp);
   return dfs(0, k, jobs);
}
int main(){
   vector<int> v = {2, 3, 4, 6, 3};
   int k = 2;
   cout << solve(v, k);
}