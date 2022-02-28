// https://leetcode.com/problems/majority-element/
// https://leetcode.com/problems/majority-element-ii/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        // Method 1 Using extra space
        // int n = nums.size();
        // vector<int> res;
        // unordered_map<int,int> mp;
        
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // int val = (n/3)+1;
        
        
        // for(auto it:mp){
        //     if(it.second>=val) res.push_back(it.first);
        // }
        
        // return res;

        // Method 2 O(n) time and O(1) space extended moore algo
        int n=nums.size(), n1=INT_MAX, n2=INT_MAX, c1=0, c2=0;   
    vector<int> ans;
    
    for(int i=0; i<n; i++)
    {
        if(nums[i]==n1) c1++;
        else if(nums[i]==n2) c2++;
        else if(c1==0)
        {
            n1=nums[i];
            c1++;
        }
        else if(c2==0)
        {
            n2=nums[i];
            c2++;
        }
        else c1--, c2--;
    }
   
    c1=0, c2=0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]==n1) c1++;
        else if(nums[i]==n2) c2++;
    }
    if(n/3<c1) ans.push_back(n1);
    if(n/3<c2) ans.push_back(n2);
    return ans;
}

int main(){


return 0;
}

/* 
it is clear that atmost 2 elements will have count greater than n/3 times
 */