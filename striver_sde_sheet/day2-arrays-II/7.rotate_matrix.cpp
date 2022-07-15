class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Method 1
        // TC n^2 , SC n^2
        // vector < vector < int >> rotated(n, vector < int > (n, 0));
        //   for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //       rotated[j][n - i - 1] = matrix[i][j];
        //     }
        //   }
        // matrix=rotated;
        
        
        
        // Method 2 Transpose + Reverse   
        // TC n^2 , SC (1)
        // Transpose of Matrix         
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // Reverse of Row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};