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

    int arr[] = {1,4,5,8};
    int arr2[] = {2,3,6,7,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr,arr2,n,m);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

return 0;
}

/* 
1 4 5 8
2 3 6 7 9 10
 */