#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
        // code here
        // Method 1 O(n) Time and Space Complexity
        int max=0,min=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[i+1]>1) max=i+1;
            else if(mp[i+1]<1) min=i+1;
        }
        
        int *res = new int[2];
        res[0] = max;
        res[1] = min;
        
        return res;
        
        // Method 2 
        
        
    }

int main(){


return 0;
}