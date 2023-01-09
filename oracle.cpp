/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int n, int m, int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m && maze[i][j] == 0)
    {
        return true;
    }
    return false;
}

int solve(vector<vector<int>> &maze, int n, int m, int i, int j, int k, vector<vector<int>> &dp)
{

    if (i > n || j > m || i < 0 || j < 0)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    for (int move = 1; move <= k; move++)
    {
        if (isSafe(maze, n, m, i + move, j))
        {
            maze[i + move][j] = 1;
            ans1 = min(ans1, 1 + solve(maze, n, m, i + move, j, k,dp));
            maze[i + move][j] = 0;
        }else break;
        if (isSafe(maze, n, m, i, j + move))
        {
            maze[i][j + move] = 1;
            ans2 = min(ans2, 1 + solve(maze, n, m, i, j + move, k,dp));
            maze[i][j + move] = 0;
        }else break;

    }
    if(ans1==INT_MAX){
        return dp[i][j] = ans2;
    }else if(ans2==INT_MAX){
        return dp[i][j] = ans1;
    }else return dp[i][j] = ans1+ans2;
}


int main()
{
    
    // int n=2,m=2;
    // int k=2;
    // vector<vector<int>> maze={
    //     {0,0},{1,0}
    // };

    int n=2,m=3;
    int k=5;
    vector<vector<int>> maze={
        {0,0,0},{1,0,0}
    };


    vector<vector<int>> dp(m,vector<int>(n,-1));
    int res=solve(maze,n,m,0,0,k,dp);
    if(res==INT_MAX) cout<<-1<<endl;
    else cout<<res<<endl;

    return 0;
}
