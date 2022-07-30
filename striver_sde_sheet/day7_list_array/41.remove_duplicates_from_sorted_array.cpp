class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Method 1 using set
        // TC and SC : O(n) and O(2n)
        // set<int> uniq_elem;
        // for(int num:nums) uniq_elem.insert(num);
        // vector<int> res(uniq_elem.begin(),uniq_elem.end());
        // nums=res;
        // return uniq_elem.size();
        
        // Method 2
        // O(n) and O(1)
        int i=0;
        nums[i++]=nums[0];
        int n=nums.size();
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[j-1]) nums[i++]=nums[j];
        }
        return i;
    }
};