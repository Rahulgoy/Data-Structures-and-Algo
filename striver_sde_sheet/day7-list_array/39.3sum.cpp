class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int sum=-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==sum){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    res.push_back(triplet);
                    
                    while(j<k and nums[j]==triplet[1]) j++;
                    while(j<k and nums[k]==triplet[2]) k--;
                }else if(nums[j]+nums[k]>sum) k--;
                else j++;
                
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        
        return res;
    }
};