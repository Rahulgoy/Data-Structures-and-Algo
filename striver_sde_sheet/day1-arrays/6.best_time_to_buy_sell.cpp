class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxi=prices[0],mini=prices[0],max_profit=0;
        // for(int i=0;i<prices.size();i++){
        //     if(prices[i]<mini) mini=maxi=prices[i];
        //     else if(prices[i]>mini and prices[i]>maxi) maxi=prices[i];
        //     max_profit= max(max_profit,maxi-mini);
        // }
        // return max_profit;
        
        
        int mx=prices[prices.size()-1],max_price=0,price;
        
        for(int i=prices.size()-1;i>=0;i--){
            price=prices[i];
            mx=max(mx,price);
            max_price=max(max_price,mx-price);
        }
        return max_price;
    }
};
