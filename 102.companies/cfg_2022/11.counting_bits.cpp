#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<int> vec;
    while(n>0){
    vec.push_back(n%2);
    n=n>>1;
    }
    reverse(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
    if(vec[i]==1){
    cout<<i+1<<" ";
        }
}
}

int main(){

    int n=161;
    solve(n);
return 0;
}