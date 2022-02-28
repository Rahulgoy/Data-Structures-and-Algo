#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,vector<string> &arr, int n){
    // To check if queen is already placed in the same column
    for(int row=0;row<x;row++){
        if(arr[row][y]=='Q') return false;
    }

    int row=x;
    int col=y;

    // To check if queen is placed in upper left diagonal
    while(row>=0 and col>=0){
        if(arr[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=x;
    col=y;

    // To check if queen is present in upper right diagonal
    while(row>=0 and col<n){
        if(arr[row][col]=='Q') return false;
        row--;
        col++;
    }
    return true;
}
void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n){


    if(row>=n){
        ans.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,board,ans,n);
            board[row][col]='.';
        }
    }

}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}


int main(){

    int n;
    cin>>n;

    vector<vector<string>> ans;
    ans = solveNQueens(n);
    cout<<ans[1][1]<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
            // if(ans[i][j] == 'Q') cout<<j+1<<" ";
        }   
        cout << endl;
    }


    return 0;
}

