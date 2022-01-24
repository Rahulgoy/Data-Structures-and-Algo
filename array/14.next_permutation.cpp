// https://leetcode.com/problems/next-permutation/submissions/
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int next_largest=-1,last_largest=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                next_largest=i;
            }
        }
        if(next_largest==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i=0;i<n-1;i++){
            if(nums[next_largest]<nums[i+1]){
                last_largest=i+1;
            }
        }
        
        swap(nums[next_largest],nums[last_largest]);
        sort(nums.begin()+next_largest+1,nums.end());
        
    }

int main(){


return 0;
}