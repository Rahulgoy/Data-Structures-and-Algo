// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

#include <bits/stdc++.h>
using namespace std;

// Longest palindromic substring in a given string (contigous)

string longestPalin (string S) {
        // code here
    int size=S.size();
    int  low,high;
    int start=0,end=1;
    for(int i=0;i<size;i++){
        // If string is odd
        low=i;
        high=i;
        while(low>=0 && high<size && S[low]==S[high]){
            if(high-low+1>end){
                start=low;
                end=high-low+1;
            }
            low--;
            high++;
        }

        // To consider if string is even
        low=i;
        high=i+1;
        while(low>=0 && high<size && S[low]==S[high]){
            if(high-low+1>end){
                start=low;
                end=high-low+1;
            }
            low--;
            high++;
        }
    }
    string temp=S.substr(start,end);
    return temp;  
}


int main(){

    string s = "adaba";
    cout<<longestPalin(s)<<endl;

return 0;
}