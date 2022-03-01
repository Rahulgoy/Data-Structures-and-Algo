// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    // Method 1 Kind of brute force
    //  vector<int>v;
    //  for(int i=0;i<n;i++){
    //      for(int j=0;j<n;j++){
    //          v.push_back(mat[i][j]);
    //      }
    //  }
    //  sort(v.begin(),v.end());
    //  return v[k-1];
    
    // Method 2 Based on median of a matrix
    int r=n,c=n;
     int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<r;i++){
            mini = min(mini,mat[i][0]);
            maxi = max(maxi,mat[i][c-1]);
        }
        
        int desired = k;
        while(mini<maxi){   // log2(2^32) = 32 operations
            int mid = mini+(maxi-mini)/2;  // To avoid overflow
            int place=0;
            
            for(int i=0;i<r;i++){    // O(r*log(c))
                place+=upper_bound(mat[i],mat[i]+c,mid)-mat[i];  
            }
            if(place<desired) mini = mid+1;
            else maxi=mid;
        }
        return mini;

}


int main(){


return 0;
}