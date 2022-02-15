#include <bits/stdc++.h>
using namespace std;

bool search(int arr[],int x,int l,int h){
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]==x) return true;
        else if(arr[mid]>x) h=mid-1;
        else l=mid+1;
    }
    return false;
}


bool findPair(int arr[], int size, int n){
    //code
    //  Method 1 O(n) time and space 
    if(n==0) return false;
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        int val = arr[i]-n;
        if(mp[val]>0) return true;
    }
    return false;


    // Method 2 O(nlog(n)) time and O(1) space
    // sort(arr,arr+size);
    // for(int i=0;i<size;i++){
    //     if(search(arr,arr[i]+n,i,size)) return true;
    // }
    // return false;
}



int main(){

    int arr[] = {20,30,40,50,60,70};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 50;

    cout<<findPair(arr,size,n)<<endl;


return 0;
}