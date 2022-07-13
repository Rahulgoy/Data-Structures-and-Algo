class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method 1
//         int num0=0,num1=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0) num0++;
//             else if(nums[i]==1) num1++;
//         }
//         for(int i=0;i<num0;i++) nums[i]=0;
//         for(int i=num0;i<num1+num0;i++) nums[i]=1;
//         for(int i=num0+num1;i<nums.size();i++) nums[i]=2;
        
        // Method 2 
        int second=nums.size()-1,zero=0;
        for(int i=0;i<=second;i++){
            while(nums[i]==2 && i<second) swap(nums[i],nums[second--]);
            while(nums[i]==0 && i>zero) swap(nums[i],nums[zero++]);
        }
    }
};