#include <bits/stdc++.h>
using namespace std;

#define m 4
#define n 5

void printCommonElements(int mat[m][n]){
    unordered_map<int,int> mp;
    for (int j = 0; j < n; j++)
        mp[mat[0][j]] = 1;
 

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]] = i + 1;
 
                // If this is last row
                if (i==m-1 && mp[mat[i][j]]==m)
                  cout << mat[i][j] << " ";
            }
        }
    }
        
}    



int main(){

    int mat[m][n] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
return 0;
}