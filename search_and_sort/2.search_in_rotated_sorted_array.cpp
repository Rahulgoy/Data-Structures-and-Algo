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


        int index=-1;
        cout<<target<<endl;
        if(*lower_bound(nums.begin(),nums.end(),target)==target){
            cout<<"True"<<endl;
            return index;
        }
        index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return index;
    }

int main(){

    vector<int> v = {4,5,6,7,0,1,2};
    cout<<search(v,1)<<endl;

return 0;
}