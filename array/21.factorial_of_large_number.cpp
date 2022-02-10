#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
    // code here
    vector<int> res;
    res.push_back(1);
    
    for(int i=2;i<=N;i++){
        int carry=0;
        for(int j=0;j<res.size();j++){
            int value = res[j]*i+carry;
            res[j] = value%10;
            carry=value/10;
        }
        while(carry!=0){
            res.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){

    vector<int> res;

    res = factorial(10);
   
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }

return 0;
}