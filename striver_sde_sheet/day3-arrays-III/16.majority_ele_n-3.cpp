class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Method 1
        // SC & TC = O(n)
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto num:nums) mp[num]++;
        for(auto it:mp){
            if(it.second>ceil(nums.size()/3)) res.push_back(it.first);
        }
        return res;
        
        //Method 2
        // TC & SC = O(n) & O(1)
//         int n=nums.size(), n1=INT_MAX, n2=INT_MAX, c1=0, c2=0;   
//         vector<int> ans;
    
//         for(int i=0; i<n; i++)
//         {
//             if(nums[i]==n1) c1++;
//             else if(nums[i]==n2) c2++;
//             else if(c1==0)
//             {
//                 n1=nums[i];
//                 c1++;
//             }
//             else if(c2==0)
//             {
//                 n2=nums[i];
//                 c2++;
//             }
//             else c1--, c2--;
//         }

//         c1=0, c2=0;
//         for(int i=0; i<n; i++)
//         {
//             if(nums[i]==n1) c1++;
//             else if(nums[i]==n2) c2++;
//         }
//         if(n/3<c1) ans.push_back(n1);
//         if(n/3<c2) ans.push_back(n2);
//         return ans;
    }
};