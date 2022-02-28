#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
        // code here        
        unordered_map<int,int> m;
        int count=0;
        
        for(int i=0;i<n;i++){
            count = count + m[k-arr[i]];
            m[arr[i]]++;
        }
        
        
        // TLE 150+
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]+arr[j]==k) count++;
        //     }
        // }
        return count;
    }

int main(){


return 0;
}