#include <bits/stdc++.h>
#define inf INT_MAX;
using namespace std;

int solveWordWrap(vector<int> a, int k)
{
    int n = a.size();

    //1. Extra space Matrix
    int cost[n][n];
    for(int i = 0; i < n; i++)
    {
        cost[i][i] = k - a[i];
        for(int j = i+1; j < n; j++)
        {
            cost[i][j] = cost[i][j-1] - a[j] - 1;
        }
    }

    //2. Cost matrix keeping the condition of not taking last line cost
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(cost[i][j]>0 && i==n-1 && j==n-1) cost[i][j] = 0;
            else if(cost[i][j]<0) cost[i][j] = INT_MAX;
            else cost[i][j] = cost[i][j]*cost[i][j];
        }
    }

    //3. Min Cost Array and ans Array
    int min[n]; int ans[n];

    for(int i = n-1; i>=0; i--)
    {
        min[i] = cost[i][n-1];
        ans[i] = n;
        for(int j = n-1; j>i; j--)
        {
            if(cost[i][j-1]==INT_MAX) continue;

            if(min[i] > min[j] + cost[i][j-1])
            {
                min[i] = min[j] + cost[i][j-1];
                ans[i] = j;
            }
        }
    }

return min[0];
}

int main(){

    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    int k;
    cin>>k;

    cout<<solveWordWrap(nums,k)<<endl;

return 0;
}