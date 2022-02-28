// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
#include <bits/stdc++.h>
using namespace std;

int split(string s){
    int n = s.length();
    int count,count0,count1;
    count=count0=count1=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') count0++;
        else if(s[i]=='1') count1++;

        if(count0==count1){
            count++;
            count0=count1=0;
        }
    }
    if(count==0) return -1;

    return count;
}


int main(){
    string s = "000000000";

    cout<<split(s)<<endl;

return 0;
}


//Time Complexity o(N)
// Space Complexity O(1)

/* 
Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
 */