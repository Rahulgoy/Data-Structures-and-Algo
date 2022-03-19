#include <bits/stdc++.h>
using namespace std;
#define N 4

void rotate90Clockwise(int arr[N][N]){
    // Method 1 Using Extra Space Brute force
    // int mat[N][N];
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         mat[j][N-i-1] = arr[i][j];
    //     }
    // }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++)
    //         cout << mat[i][j] << " ";
    //     cout << '\n';
    // }
    // Method 2 
    // Clockwise
    // for(int i=0;i<N/2;i++){
    //     for(int j=i;j<N-i-1;j++){
    //         int temp = arr[i][j];
    //         arr[i][j] = arr[N-j-1][i];
    //         arr[N-j-1][i] = arr[N-i-1][N-j-1];
    //         arr[N-i-1][N-j-1] = arr[j][N-i-1];
    //         arr[j][N-i-1] = temp;
    //     }
    // }
    // Anti Clockwise
    for(int i=0;i<N/2;i++){
        for(int j=i;j<N-i-1;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][N-i-1];
            arr[j][N-i-1] = arr[N-i-1][N-j-1];
            arr[N-i-1][N-j-1] = arr[N-j-1][i];
            arr[N-j-1][i] = temp;
        }
    }
}



void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main(){

    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;

return 0;
}