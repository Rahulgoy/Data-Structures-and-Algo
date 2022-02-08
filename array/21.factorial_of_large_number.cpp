#include <bits/stdc++.h>
using namespace std;

int dp[1001]={0};
long long fact(int n)
{
    if (n >= 0) 
    {
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) 
        {
            dp[i] = i * dp[i - 1];
        }
        return dp[n];
    }
    return 1;
}

vector<int> factorial(int N){
    // code here
    long long num = fact(N);
    cout<<num<<endl;
    vector<int> v;
    while(num>0){
        int temp = num%10;
        v.push_back(temp);
        num = num/10;
    }
    reverse(v.begin(),v.end());
    return v;
    
}

int main(){

    vector<int> res;

    res = factorial(10);
    cout<<fact(5)<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }

return 0;
}