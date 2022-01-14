#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int n){

    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // return arr;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6};
     
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr,n);
    

    return 0;
}