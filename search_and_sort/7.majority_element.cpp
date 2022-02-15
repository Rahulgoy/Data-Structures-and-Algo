#include <bits/stdc++.h>
using namespace std;

// n/2
int majorityElement(int a[], int size)
    {
        
        // your code here
        // Method 1 O(n) time and space complexity
        // unordered_map<int,int> mp;
        // int n = size/2;
        // int res=-1;
        
        // for(int i=0;i<size;i++){
        //     mp[a[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second>n) return it.first;
        // }
        // return res;
        
        
        // Method 2 Moore's Algorithm
        int ele,count=0;
        for(int i=0;i<size;i++){
            if(ele==a[i]){
                count++;
            }else if(count==0){
                ele=a[i];
                count++;
            }else count--;
        }
        count=0;
        for(int i=0;i<size;i++){
            if(a[i]==ele) count++;
        }
        return (count>size/2) ? ele:-1;
    }

int main(){

    int arr[] = {3,1,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<majorityElement(arr,n)<<endl;
return 0;
}