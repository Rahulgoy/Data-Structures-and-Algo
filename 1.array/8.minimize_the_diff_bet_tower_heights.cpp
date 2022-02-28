#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        // code here
        
        
        sort(arr, arr+n);
        int diff = arr[n-1]- arr[0];
        
        int maxi = arr[n-1];
        int mini = arr[0];
        
        for(int i=1; i<n; i++)
        {
            if(arr[i]-k<0)  // So that the tower height is never negative
            continue;
            
            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[n-1]-k, arr[i-1]+k);
            diff = min(diff, maxi-mini);
        }
        return diff;
        
    }

int main(){

    int arr[] = {3,2,6,1,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k= 3;

    cout<<getMinDiff(arr,n,k)<<endl;

return 0;
}