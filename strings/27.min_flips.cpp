#include <bits/stdc++.h>
using namespace std;

int minFlips (string S)
{
    // your code here
    int n=S.length();
    int result=0;
    int count=1;
    for(int i=0;i<n-1;i++){
        if(S[i]!=S[i+1]){
            if(count>1){
                result= result+ (count/2);
                count=1;
            }
        }else count=count+1;
    }
    result= result + (count/2);
    return result;
}

int main(){

    string s="001";
    cout<<minFlips(s)<<endl;


return 0;
}