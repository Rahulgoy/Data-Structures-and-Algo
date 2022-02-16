#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
    {
        //Your code here
        // Method 1 with TLE O(n^2) time, O(1) space
        // int sum=INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==0) return true;
        //     sum = arr[i];
        //     for(int j=i+1;j<n;j++){
                
        //         sum = sum+arr[j];
        //         if(sum==0) return true;
        //     }
            
        // }
        // return false;
        
        
        // Method 2   O(n) time and space
        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum]++;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp[sum]>0) return true; // concept is if same sum repeats than that means the in between sum of elements is zero.
            else mp[sum]++;
        }
        return false;
    }

int main(){

    int arr[] = {10,-10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subArrayExists(arr,n)<<endl;

return 0;
}