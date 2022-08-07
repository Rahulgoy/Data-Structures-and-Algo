class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Method 1 Using Bit Manipulation
        // int res=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     res=res^nums[i];
        // }
        // return res;
        
        // Method 2 Binary Search
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) ||(mid%2==1 and nums[mid]==nums[mid-1])){
                low=mid+1;
            }else high=mid;
            
        }
        return nums[low];
    }
};