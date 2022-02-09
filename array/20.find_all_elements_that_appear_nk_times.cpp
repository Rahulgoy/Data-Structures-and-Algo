#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        // Method 1 Using extra space
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int val = (n/3)+1;
        
        
        for(auto it:mp){
            if(it.second>=val) res.push_back(it.first);
        }
        
        return res;

        // Method 2
        
}

int main(){


return 0;
}