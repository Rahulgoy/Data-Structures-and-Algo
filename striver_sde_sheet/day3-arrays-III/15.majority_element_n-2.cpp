class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Method 1
        // SC & TC = O(n)
        // unordered_map<int,int> mp;
        // for(auto num:nums) mp[num]++;
        // for(auto it:mp){
        //     if(it.second>ceil(nums.size()/2)) return it.first;
        // }
        // return 0;
        
        // Method 2 
        // TC & SC = O(n) & O(1)
        int count=1;
        int elem=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0){
                elem=nums[i];
                count=1;
            }
            else if(nums[i]==elem) count++;
            else count--;
        }
        return elem;
    }
};