#include <bits/stdc++.h>
using namespace std;

long long int factorial(int n, long long int dp[])
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    long long int rres = factorial(n - 1, dp);
    long long int cRes = n * rres;
    dp[n] = cRes;
    return dp[n];
}
int binomialCofficient(int n, int r, long long int dp[])
{
    if (r > n)
        return 0;
    if (r == n)
        return 1;
    /* long long int n1 = factorial(n, dp);
    long long int nr = factorial(n - r, dp);
    long long int r1 = factorial(r, dp);
    cout << n1 << ": " << nr << ": " << r1 << ": ";
    long long int res = n1 / nr;
    // res = res % 1000000007;
    cout << res << ": "; */
    int ncr = factorial(n, dp) / (factorial(n - r, dp) * factorial(r, dp));
    return ncr;
}
int main()
{
    int n, r;
    cin >> n >> r;
    long long int dp[100];
    memset(dp, -1, sizeof(dp));
    // cout << factorial(n, dp);
    cout << binomialCofficient(n, r, dp);
    return 0;
}
