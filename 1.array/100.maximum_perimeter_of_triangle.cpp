#include <bits/stdc++.h>
using namespace std;

int maxPerimeter(int arr[], int n){

    // Complete the function
    // sort(arr,arr+n);
    int maxi=-1;
    // for(int i=0;i<n-2;i++){
    //     if(arr[i]+arr[i+1]>arr[i+2]){
    //         int sum = arr[i]+arr[i+1]+arr[i+2];
    //         maxi = max(maxi,sum);
    //     }
    // }
    
    
    priority_queue<int> que;
    for(int i=0;i<n;i++){
        que.push(arr[i]);
    }
    
    while(!que.empty()){
        
        int a = que.top(); que.pop();
        if(que.empty()) break;
        int b = que.top(); que.pop();
        if(que.empty()) break;
        int c = que.top(); que.pop();
        cout<<a<<" "<<b<<" "<<c<<endl;
        if(b+c>a){
            int sum = a+b+c;
            maxi = max(maxi,sum);
            break;
        }
        que.push(b);
        que.push(c);

    }

    return maxi;
    
}



int main(){

    int arr[] = {33, 6, 20, 1, 8,
                    12, 5, 55, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxPerimeter(arr,n)<<endl;

    return 0;
}

/* 
First sorting method definitely has O(n) complexity

But using priority queue it can be optimized
O(n) time to heapify the array.
And comparing the top 3 elements
Though the time for removing an element is O(nlogn) which is worst case.

 */