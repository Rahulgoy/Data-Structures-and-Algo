#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n){
        // code here
        // Method 1
        // vector<int> left(n);
        // vector<int> right(n);
        // // int left[] = new int[n];
        // // int right[] = new int[n];
        // long long sum=0;
        
        
        
        // left[0] = arr[0];
        // for(int i=1;i<n;i++){
        //     left[i] = max(left[i-1],arr[i]);
        // }
        // right[n-1] = arr[n-1];
        // for(int i=n-2;i>=0;i--){
        //     right[i] = max(right[i+1],arr[i]);
        // }
        
        // for(int i=0;i<n;i++){
        //     sum += min(left[i],right[i]) - arr[i];
        // }
        
        // return sum;
        
        // Method 2   O(n) time, O(1) space 
        
        
        int low=0,high=n-1,max_left=0,max_right=0;
        long long sum = 0;
        
        while(low<=high){
            if(arr[low]<arr[high]){
                if(arr[low]>max_left){
                    max_left = arr[low];
                }else{
                    sum+= (max_left-arr[low]);
                }
                low++;
            }else{
               if(arr[high]>max_right){
                   max_right = arr[high];
               }else{
                   sum+= max_right-arr[high];
               }
               high--;
            }
        }
        return sum;
        
    }

int main(){


return 0;
}