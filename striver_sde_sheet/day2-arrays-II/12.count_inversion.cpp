#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,vector<int> &temp,int start,int mid,int end){
    int inv_count=0;
    int i=start,j=mid,k=start;
    while((i<=mid-1) && (j<=end)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inv_count = inv_count+(mid-i);
        }
    }
    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= end)
        temp[k++] = arr[j++];
    
    for(i=start;i<=end;i++){
        arr[i]=temp[i];
    }

    return inv_count;

}

int merge_Sort(vector<int> &arr,vector<int> &temp,int start,int end){

    int mid,inv_count=0;
    if(end>start){
        mid=start+(end-start)/2;
        inv_count+=merge_Sort(arr,temp,start,mid);
        inv_count+=merge_Sort(arr,temp,mid+1,end);

        inv_count+=merge(arr,temp,start,mid+1,end);
    }
    return inv_count;
}

int main(){

    vector<int> arr={5,3,2,1,4};
    int n=5;
    vector<int> temp(n);

    // Method 1 Brute Force O(n^2)
    // int count=0;
    // for(int i=0;i<arr.size();i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]>arr[j]) count++;
    //     }
    // }
    // return count;

    // Method 2 Using Merge Sort O(nlogn)
    int ans = merge_Sort(arr,temp,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 


return 0;
}