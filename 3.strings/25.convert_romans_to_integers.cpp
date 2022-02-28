#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
    // code here

    unordered_map<char, int> val = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int n = str.length();
    int total=0;
    for(int i=0;i<n;i++){
        if(val[str[i]]>=val[str[i+1]]) total+=val[str[i]];
        else{
            total=total+val[str[i+1]]-val[str[i]];
            i++;
        }
    }
    return total;
}
int main(){

    string s="XIX";
    cout<<romanToDecimal(s)<<endl;

return 0;
}