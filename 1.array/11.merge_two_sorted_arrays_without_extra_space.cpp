// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {

	    /* Method 1 Runtime error 203/315 test cases passed
	   for(int i=0;i<n;i++){
	       if(arr1[i]>arr2[0]){
	           swap(arr2[0],arr1[i]);
    	        sort(arr2,arr2+m);
	       }
	   } */
	    
	    int i=n-1;
	   int j=0;
	   
	   while(i>=0 && j<m){
	       if(arr1[i]>arr2[j]){
	           swap(arr1[i],arr2[j]);
	       }
	       
	       i--;
	       j++;
	       
	       
	   }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
	}

int main(){


return 0;
}

/* 
Another method is gap method
initial gap is m+n/2
if(arr[i]>arr[i+gap]) swap
if index moves out of range of m+n
then gap=gap/2
follow this till gap>=1
 */