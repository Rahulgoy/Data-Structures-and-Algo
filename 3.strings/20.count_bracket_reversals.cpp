#include <bits/stdc++.h>
using namespace std;

int countRev (string s) {
    if(s.size() & 1) return -1; // To check if length of string is odd
    int curr=0, res = 0;
    for(auto it:s) {
        if(it == '{') curr++;
        else if(it == '}') curr--;
        cout<<curr<<" "<<res<<endl; 
        if(curr < 0){ 
            res++; curr+=2;
        }
    }
    res += curr/2;  //to get ceil value
    return res;
}

int main(){

    string s = "}{{}}}{{";
    cout<<countRev(s)<<endl;
    return 0;
}