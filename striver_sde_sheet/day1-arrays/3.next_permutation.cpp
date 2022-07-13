class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int next_largest=-1,last_largest=-1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) next_largest=i;
        }
        if(next_largest==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[next_largest]<nums[i+1])
                last_largest=i+1;
        }
        swap(nums[next_largest],nums[last_largest]);
        sort(nums.begin()+next_largest+1,nums.end());
        
    }
};