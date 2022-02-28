// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> arr;
        vector<vector<int>> res( N , vector<int> (N, 0));  // rather than declaring new vector we can simple replace values in Mat as well and return Mat
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr.push_back(Mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        
        int k=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                res[i][j] = arr[k];
                k++;
            }
        }
        return res;
    }

int main(){


return 0;
}