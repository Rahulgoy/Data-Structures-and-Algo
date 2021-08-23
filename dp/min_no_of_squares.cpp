#include <bits/stdc++.h>
using namespace std;

int calNum(int n)
{
    int res = 0;
    while (n >= 1)
    {
        if (n == 3 || n == 2 || n == 1)
        {
            res = res + n;
            break;
        }

        double q = sqrt(n);
        n = n - (int(q) * int(q));
        res = res + 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << calNum(n);

    return 0;
}