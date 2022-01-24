#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
        int temp=-1;
        int n = nums.size();
        // Method 1     465ms, 100 MB
        /*unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto x:mp){
            if(x.second>1) temp = x.first;
        }
        return temp;
        */
        
        // Method 2      244ms,  61 MB
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) temp = nums[i];
        }
        return temp;
    }

int main(){

    vector<int> res={1,2,5,6,2,8,2};

    cout<<findDuplicate(res)<<endl;



return 0;
}