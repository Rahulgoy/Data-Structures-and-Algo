#include <bits/stdc++.h>
using namespace std;

string convert(string s,string str[]){
    string res="";

    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]==' ') res=res+'0';
        else{
            int indx = s[i]-'A';
            res = res+str[indx];
        }
    }
    return res;
}
int main(){
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
    string s="HELLO WORLD";
    string res = convert(s,str);
    cout<<res<<endl;
    return 0;
}