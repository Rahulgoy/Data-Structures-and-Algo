#include <bits/stdc++.h>
using namespace std;


string countandsay(int n){
    if(n==1) return "1";
    if(n==2) return "11";

    string s="11";

    for(int i=3;i<=n;i++){
        string t="";
        
        s=s+"$";
        cout<<s.length()<<endl;
        int c=1;
        for(int j=1;j<s.length();j++){
            if(s[j]!=s[j-1]){
                t=t+to_string(c)+s[j-1];
                c=1;
            }else c++;
        }
        s=t;
    }
    return s;

}


string count(string s){
    int n = s.size();
    int c=1;
    string res;
    for (int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            c++;
        }else{
            res.push_back(c+'0');
            res.push_back(s[i]);
            c=1;
        }
    }
    res.push_back(c+'0');
    res.push_back(s[n-1]);
    return res;

}

string rec_countandsay(int n){
    if(n==1) return "1";

    string res = rec_countandsay(n-1);
    return count(res);
}



int main(){

    int n = 6;

    string s = rec_countandsay(n);
    cout<<s<<endl;

    return 0;
}

// Recursive is very much faster than normal