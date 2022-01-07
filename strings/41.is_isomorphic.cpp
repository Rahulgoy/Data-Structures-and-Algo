// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

 bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n=str1.length(),m=str2.length();
      if(n!=m) return false;
      int i=1;
      int s1[256]={0},s2[256]={0};
      
      
       for(int i=0;i<n;i++){
           if(!s1[str1[i]] and !s2[str2[i]]){
               s1[str1[i]] = str2[i];
               s2[str2[i]] = str1[i];
           }else if(s1[str1[i]]!=str2[i]) return false;
       }
       return true;
        
    }
int main(){

    string s1="aab";
    string s2="xxy";

    cout<<areIsomorphic(s1,s2)<<endl;

return 0;
}