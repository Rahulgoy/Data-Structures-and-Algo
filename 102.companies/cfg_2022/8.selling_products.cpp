#include <bits/stdc++.h>
using namespace std;

int deleteProducts(vector<int> ids , int m)
{
    int n = ids.size() ;
    unordered_map<int, int> count;

    for (int i = 0; i < n; i++)
        count[ids[i]]++;
 
    vector<int> fre_arr(n + 1, 0);
    for (auto it : count) {
        fre_arr[it.second]++;
    }
    int ans = count.size();
 
    for (int i = 1; i <= n; i++) {
        int temp = fre_arr[i];
        if (temp == 0)
            continue;
 
        int t = min(temp, m / i);
        ans -= t;
        m -= i * t;
    }
    return ans;
}

int main(){

    // vector<int> ids={1,1,1,2,3,2};
    // int m=2;
    vector<int> ids={1,1,5,5};
    int m=2;
    cout<<deleteProducts(ids,m)<<endl;

    return 0;
}