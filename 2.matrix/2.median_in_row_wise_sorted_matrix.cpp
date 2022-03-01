//  https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        // O(rclog(rc) time and O(r*c) space
        // vector<int> res;
        // int k=0;
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         res.push_back(matrix[i][j]);
        //     }
        // }
        // sort(res.begin(),res.end());
        // return res[(r*c)/2];
        
        
        // Method 2  Time Complexity O(32*r*log(c)
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<r;i++){
            mini = min(mini,matrix[i][0]);
            maxi = max(maxi,matrix[i][c-1]);
        }
        
        int desired = ((r*c)+1)/2;
        while(mini<maxi){   // log2(2^32) = 32 operations
            int mid = mini+(maxi-mini)/2;  // To avoid overflow
            int place=0;
            
            for(int i=0;i<r;i++){    // O(r*log(c))
                place+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();  //number of elements smaller than mid
            }
            if(place<desired) mini = mid+1;
            else maxi=mid;
        }
        return mini;
    }

int main(){


return 0;
}