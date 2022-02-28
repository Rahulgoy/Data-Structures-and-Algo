#include <bits/stdc++.h>
using namespace std;

int fib(int n, int arr[])
{
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    // for (int i = 0; i < n + 2; i++)
    //     cout << arr[i] << " ";
    return arr[n - 1];
}
int main()
{

    int n;
    cin >> n;
    int arr[n + 2];
    memset(arr, -1, n);
    cout << fib(n, arr);

    return 0;
}