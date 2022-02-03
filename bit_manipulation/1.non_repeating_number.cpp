#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        vector<int> res;
        int n=nums.size();
        // Method 1
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]) res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) i+1;
            else if(nums[i]!=nums[i-1] and i+1<n and nums[i]==nums[i+1]) i+1;
            else if(nums[i]!=nums[i-1] and i+1<n and nums[i]!=nums[i+1]) res.push_back(nums[i]);
            else if(i==n-1 and nums[i]!=nums[i-1]) res.push_back(nums[i]);
        }
        return res;
        
        // Method 2 using extra space
        // map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==1) res.push_back(it.first);
        // }
        // return res;
    }

int main(){


return 0;
}