// 34. https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i =0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}


int countChar(string s){
    int flag = 0,count=0;
    int n = s.length();

    while(n>0){

        if(isPalindrome(s)){
            flag=1;
            break;
        }else{
            count++;

            s.erase(s.begin()+s.length()-1);
            
        }
    }
    if(flag) return count;
}




int main(){

    string s="AAAAA";

    cout<<countChar(s)<<endl;

return 0;
}

// O(n) time complexity
// O(1) space complexity