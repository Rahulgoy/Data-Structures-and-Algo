#include <bits/stdc++.h>
using namespace std;

/* Code work but Time limit exceeded.
bool isPalindrome(string s){
        int n = s.length();
        if(n==1) return true;
        
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
        
}
int palindromeSubStrs(string s) {
    // code here
    int n = s.length(),count=0;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        for(int len=1;len<=n-i;len++){
            string t = s.substr(i,len);
            if(isPalindrome(t)){
                if(mp[t]==0){ 
                    
                    count++;
                    mp[t]++;
                    
                }
            }
        }
    }
    return count;
} */


void solve(string str, int i, int j, set<string> &s) {
    while(i>=0 and j<str.size() and str[i]==str[j]) {
        s.insert(str.substr(i, j-i+1));
        i--;
        j++;
    }
}

int palindromeSubStrs(string str) {
    set<string> s;
    for(int i=0; i<str.size(); i++) {
        solve(str, i, i, s);
        solve(str, i, i+1,s); // Covers even odd case i.e a-odd , aa-even
    }
    return s.size();
}

int main(){

    string s="geek";

    cout<<palindromeSubStrs(s)<<endl;
return 0;
}