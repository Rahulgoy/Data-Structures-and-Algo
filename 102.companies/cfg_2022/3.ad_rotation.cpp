#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    string str;
      while(n){
      if(n & 1) // 1
        str+='1';
      else // 0
        str+='0';
      n>>=1; // Right Shift by 1 
    }   
    reverse(str.begin(),str.end());
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            str[i]='1';
        }else if(str[i]=='1') str[i]='0';
    }

    int k=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0') k=i;
        else break;
    }
    str = str.substr(k+1,str.length()-k+1); 

    // cout<<str<<endl;

    int ans=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='1') ans=ans*2+1;
        else ans=ans*2;
    }
    return ans;
}

int main(){

    int n = 50;
    cout<<solve(n)<<endl;
return 0;
}