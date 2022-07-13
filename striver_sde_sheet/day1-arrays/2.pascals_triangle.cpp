class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            int j=1;
            while(j!=i+1){
                if(j==i) temp.push_back(1);
                else{
                    int e=res[i-1][j-1]+res[i-1][j];
                    temp.push_back(e);
                }
                j++;
            }
            res.push_back(temp);
            
        }
        return res;
        
        // More clean code
//         vector<vector<int>> r(numRows);

//         for (int i = 0; i < numRows; i++) {
//             r[i].resize(i + 1);
//             r[i][0] = r[i][i] = 1;
  
//             for (int j = 1; j < i; j++)
//                 r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
//         }
        
//         return r;
        
    }
};