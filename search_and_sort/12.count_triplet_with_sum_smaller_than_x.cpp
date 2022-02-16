#include <bits/stdc++.h>
using namespace std;

	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	   // Method 1 O(n^3) time and only 310/580 test cases passed
	   // sort(arr,arr+n);
	   // long long count=0;
	   // for(int i=0;i<n;i++){
	   //     for(int j=i+1;j<n;j++){
	   //         for(int k=j+1;k<n;k++){
	   //             if((arr[i]+arr[j]+arr[k])<sum){
	   //                 count++;
	   //             }
	   //         }
	   //     }
	   // }
	   // return count;
	    
	   // Method 2 (n^2) time complexity
	   sort(arr,arr+n);
	   int low,high;
	   long long count=0;
	   for(int i=0;i<n;i++){
	       low=i+1;
	       high = n-1;
	       
	       while(low<high){
	           if(arr[low]+arr[high]<sum-arr[i]){
	               count=count+(high-low);
	               low++;
	           }else if(arr[low]+arr[high]>=sum-arr[i]) high--;
	       }
	   }
	   return count;
	}

int main(){

    long long arr[] = {-2,0,1,3};
    long long sum = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<countTriplets(arr,n,sum)<<endl;
return 0;
}