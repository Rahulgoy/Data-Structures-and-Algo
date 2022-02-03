// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int profit =0;
        int mini,maxi;
        mini=maxi=prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<mini){
                mini=maxi=prices[i];
            }else if(prices[i]>mini and prices[i]>maxi){
                maxi = prices[i];
            }
            profit = max(profit,maxi-mini);
        }
        return profit;
    }

int main(){

    vector<int> v = {7,1,5,3,6,4};

    cout<<maxProfit(v)<<endl;

return 0;
}

/* 
Sample inputs
[7,1,5,3,6,4]
[2,4,1]
[4,3,2]
[6,1,3,1,5]

Outputs
5
2
0
4
 */