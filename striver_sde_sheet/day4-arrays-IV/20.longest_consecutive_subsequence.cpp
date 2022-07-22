class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // Method 1 O(nlogn) using sort
//         sort(nums.begin(),nums.end());
        
//         if(n==0) return 0;
//         int count=0,max_count=0;
//         for(int i=0;i<n-1;i++){
//             if(nums[i]+1==nums[i+1]) count++;
//             else if(nums[i]==nums[i+1]) continue;
//             else count=0;
//             max_count=max(count,max_count);
//         }
//         return max_count+1;
        
        //Method 2
        set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }
        return longestStreak;
    }
};