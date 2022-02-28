#include <bits/stdc++.h>
using namespace std;
// Transform A to B

int transform(string s1,string s2){
    int m = s1.length(), n=s2.length();
    if(m!=n) return -1;

    int chr[256];
    memset(chr,0,sizeof(chr));

    for(int i=0;i<m;i++){
        chr[s1[i]]++;
    }
    for(int i=0;i<m;i++){
        chr[s2[i]]--;
    }
    for(int i=0;i<256;i++){
        if(chr[i]) return -1;
    }

    int res=0;
    for(int i=n-1,j=n-1;i>=0;){

        while(i>=0 && s1[i]!=s2[j]){
            res++;
            i--;
        }
        if(i>=0){
            i--;j--;
        }
    }
    return res;
}

int main(){

    string s1="EACBD";
    string s2="EABCD";

    cout<<transform(s1,s2)<<endl;
    return 0;
}