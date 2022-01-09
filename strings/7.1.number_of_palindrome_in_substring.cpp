#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isPalindrome(string s){
    int n = s.length();
    if(n<2) return 0;
    
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return 0;
    }
    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int n = s.length();
    int count=0;
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++){
            count+=isPalindrome(s.substr(i, len));
        }

    cout<<count;
    return 0;
}

// It is different from ones in number of palindrome in subsequence
// As subsequence and substring are different
// Substring is of contigous characters while subsequence can be a combination of different characters of a string.