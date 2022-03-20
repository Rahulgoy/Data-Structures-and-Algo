#include <bits/stdc++.h>
using namespace std;

string complement(string s){
    unordered_map<char,char> mp;
    mp['A']='T';
    mp['T']='A';
    mp['C']='G';
    mp['G']='C';
    // reverse(s.begin(),s.end());
    // for(int i=0;i<s.length();i++){
    //     s[i]=mp[s[i]];
    // }
    // return s;

    // Method 2
    string res="";
    for(int i=s.length()-1;i>=0;i--){
        res+=mp[s[i]];
    }
    return res;
}

int main(){

    // string s="ATGC"; //GCAT
    string s="ACCGGGTTTT"; //AAAACCCGGT
    // string s="GTCAG";  //CTGAC
    cout<<complement(s)<<endl;

return 0;
}