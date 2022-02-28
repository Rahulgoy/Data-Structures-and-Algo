// Kadane algo
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        // long long int max=-9999999;
        // long long int sum=0;
        // for(int i=0;i<n;i++){
        //     sum=arr[i];
        //     for(int j=i+1;j<n;j++){
        //         if(sum>max){
        //             max = sum;
        //         }
        //         sum=sum+arr[j];
        //         if(sum>max){
        //             max = sum;
        //         }
                
        //     }
        // }
        //  if(sum>max){
        //             max = sum;
        //         }
        // return max;
        
        
        long long s=0;
        long long ans=INT_MIN;
        // Your code here
        for(int i=0;i<n;i++){
            s+= arr[i];
            ans = max(ans,s);
            if(s<0) s=0;
        }
        
        return ans;
}


int main(){

    int arr[] = {1,2,3,-2,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxSubarraySum(arr,n)<<endl;

return 0;
}