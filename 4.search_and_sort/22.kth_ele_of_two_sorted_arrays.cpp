#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   
        // Method 1
        // int i=n-1,j=0;
        // while(i>=0 and j<m){
        //     if(arr1[i]>arr2[j]){
        //         swap(arr1[i],arr2[j]);
        //     }
        //     i--;
        //     j++;
            
        // }
            
        // sort(arr1,arr1+n);
        // sort(arr2,arr2+m);
        
        
        // if(k>n){
        //     return arr2[k-n-1];
        // }else{
        //     return arr1[k-1];
        // }
        
        // Method 2 Using STL
        int arr[m+n];
        merge(arr1,arr1+n,arr2,arr2+m,arr);
        return arr[k-1];
        
        // Method 3 using Multisets
        multiset<int>a; // duplicate elements can be stored and elements are stored in sorted order.
        for(int i=0;i<n;i++){
           a.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
               a.insert(arr2[i]);
        }
        int index=1;
        for(auto i:a){
            if(index==k){
                   return i;
            }
               index++;
        }
        return -1;
    }

int main(){

    int arr[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int k=5;
    cout<<kthElement(arr,arr2,n,m,k)<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;

    

return 0;
}

/* 
1 4 5 8
2 3 6 7 9 10
 */