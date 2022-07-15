class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int columns = matrix[0].size();
        
//         int low=0,high=rows*columns-1;
              
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             int element = matrix[mid/columns][mid%columns];
//             if(element==target) return true;
//             else if(element>target) high = mid-1;
//             else if(element<target) low = mid+1;
//         }
//         return false;
        
        
        int rows = 0;
        int cols = matrix[0].size()-1;
        while(rows<matrix.size() and cols>=0){
            if(matrix[rows][cols]==target) return true;
            else if(matrix[rows][cols]<target){
                rows++;
            }else cols--;
        }
        return false;
    }
};