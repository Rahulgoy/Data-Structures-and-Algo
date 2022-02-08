#include <bits/stdc++.h>
using namespace std;

int minSub(vector<int> &v,int target){
    int n = v.size();

    int min_length=INT_MAX,sum=0;
    int left=0,right=0;

    if(target == 0 || v.size() == 0) return 0;

    while(right<n){
        sum += v[right];

        while(sum>=target){
            min_length = min(min_length,right-left+1);

            sum -= v[left];
            left++;

        }
        right++;
    }
    return min_length==INT_MAX?0:min_length;


    /*  M2
    int n = nums.size();
        long int min_l=9999999999;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                
                if(i==j){
                    sum = nums[j];
                    if(sum>=target) return min_l=1;
                }else{
                    sum = sum+nums[j];
                    if(sum>=target && (j-i)<min_l){
                        min_l = j-i;
                        break;
                    }
                }
                
                
            }
        }
        if(min_l==9999999999) return 0;
        return min_l+1;
     */

}

int main(){

vector<int> v={2,3,1,2,4,3};
cout<<minSub(v,7)<<endl;

return 0;
}