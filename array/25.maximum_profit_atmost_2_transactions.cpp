// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        
        int ma=prices[n-1];
        int mi = prices[0];
        
        for(int i=n-2;i>=0;i--){
            if(prices[i]>ma) ma=prices[i];
            dp[i] = max(dp[i+1],ma - prices[i]);
        }
        for(int i=1;i<n;i++){
            if(prices[i]<mi) mi=prices[i];
            dp[i] = max(dp[i-1],dp[i]+(prices[i]-mi));
        }
        return dp[n-1];
        
        
    }

int main(){


return 0;
}