#include <bits/stdc++.h>
class Solution {
public:
    void setZ(vector<vector<int>>& matrix,int i,int j){
        int m = matrix.size();
        int n = matrix[i].size();
        
        for(int a=0;a<m;a++){
            matrix[a][j]=0;
        }
        for(int a=0;a<n;a++){
            matrix[i][a]=0;
        }
    }
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        // Method 1 without inplace         
//         vector<vector<int>> res(matrix.begin(),matrix.end());
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[i].size();j++){
//                 if(matrix[i][j]==0){
//                     setZ(res,i,j);
//                 }
//             }
//         }
        
//         matrix=res;
        
        // Method 2 with inplace
        bool row=false,col=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    if(i==0) row=true;
                    if(j==0) col=true;
                    matrix[0][j]=matrix[i][0]=0;  // to set starting elem of that row and column to zero
                    
                }
            }
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(col){
            for(int i=0;i<matrix.size();i++) matrix[i][0]=0;
        }
        if(row){
            for(int i=0;i<matrix[0].size();i++) matrix[0][i]=0;
        }
        
    }
};