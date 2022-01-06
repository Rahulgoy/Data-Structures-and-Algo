#include <bits/stdc++.h>
using namespace std;


// If we only had to tell if it is possible to rearrange
int rearrangeString(string str)
{
    //code here
    unordered_map<char,int> m;
    int n = str.length();
    int max=-1;
    for(int i=0;i<n;i++){
        m[str[i]]++;
        if(m[str[i]]>max) max=m[str[i]];
    }
    
    if(max<=n-max+1) return 1;
    return 0;
}



int main(){


return 0;
}