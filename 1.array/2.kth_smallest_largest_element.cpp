#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // Method 1  O(nlogn) complexity
        sort(arr,arr+r+1);
        return arr[k-1];
        
        //Method 2  but time limit exceeds and space complexity is not one
        // O(n+klogn) and space is O(n)
        /*priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0;i<=r;i++){
            pq.push(arr[i]);
        }
        int res=0;
        while(k>0){
            res=pq.top();
            pq.pop();
            k--;
        }
        return res;*/
        
        //Method 3
        
    }


int main(){

    int arr[] = {2,5,7,8,1,6};

    int r = sizeof(arr)/sizeof(arr[0]);

    cout<<kthSmallest(arr,0,r,3)<<endl;

return 0;
}