#include <bits/stdc++.h>
using namespace std;

long long int merge1(long long a[],long long temp[],long long int left,long long int mid,long long int right){
    int i,j,k;
    long long int inv=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1) and (j<=right)){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            inv+=(mid-i);
        }
    }
    while(i<=(mid-1)){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++] = a[j++];
    }
    for(int m=left;m<=right;m++){
        a[m] = temp[m];
    }
    return inv;
}

long long int mergesort(long long a[],long long temp[],long long int left,long long int right){
    long long int inv=0;
    if(left<right){
        long long int mid = (left+right)/2;

        inv+= mergesort(a,temp,left,mid);
        inv+=mergesort(a,temp,mid+1,right);
        inv+= merge1(a,temp,left,mid+1,right);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    // Method 1 Brute force O(n^2)
    long long int count=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j]) count++;
        }
    }
    return count; 

    long long temp[N];
    mergesort(arr,temp,0,N-1);
}


int main(){

    long long int arr[] = {2,4,1,3,5};
    long long n = sizeof(arr)/sizeof(arr[0]);
    cout<<inversionCount(arr,n)<<endl;
return 0;
}