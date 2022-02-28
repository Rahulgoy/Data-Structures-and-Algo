#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        // int index=-1;
        // int n = nums.size();
        // if(target<nums[0]){
        //     for(int i=n-1;i>=0;i--){
        //         if(nums[i]==target){index=i;break;}
        //     }
        // }else{
        //     for(int i=0;i<n;i++){
        //         if(nums[i]==target){index=i;break;}
        //     }
        // }
        // return index;

        // Don't know why but it doesn't work
        // int index=-1;
        // cout<<target<<endl;
        // if(*lower_bound(nums.begin(),nums.end(),target)!=target){
        //     cout<<"True"<<endl;
        //     return index;
        // }
        // index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // return index;


        int low=0, high=nums.size()-1;
        
        while(low<high) {
            int mid = low + (high-low)/2;
            
            if (nums[mid]==target) {
                return mid;
            } 
            //result is guaranteed to be in the right. Example: [3 4 5 1 2], 1
            else if (nums[mid]> nums[high] && nums[low]> target) {
                low = mid+1;
            }
            //result is guaranteed to be in the left. Example: [4 5 1 2 3], 5
            else if (nums[mid]< nums[low] && nums[high]< target) {
                high = mid;
            }
            else if (nums[mid]<target) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        
        return nums[low] == target ? low : -1;


    }

int main(){

    vector<int> v = {4,5,6,7,0,1,2};
    cout<<search(v,1)<<endl;

return 0;
}