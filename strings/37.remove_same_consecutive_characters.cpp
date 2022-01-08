#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string S)
    {
        // code here.
        int n = S.length();
        string t="";
        int i=0;
        for(i=0;i<n-1;i++){
            if(S[i]!=S[i+1]){
                t=t+S[i];
            }
        }
        t=t+S[i];
        
        return t;
    }

int main(){

    string s = "aaabbcdd";

    cout<<removeConsecutiveCharacter(s)<<endl;
return 0;
}