#include <bits/stdc++.h>
using namespace std;

 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long int product=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) count++;
            else product=product*nums[i];
        }
        vector<long long int> res;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(count==1){
                    res.push_back(product);
                }else res.push_back(0);
            }else{
                if(count>=1){
                    res.push_back(0);
                }else res.push_back(product/nums[i]);
            }
            
        }
        return res;
    }

int main(){


return 0;
}