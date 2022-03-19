#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int n = s.length();
    int count=0;

    // Method 1 O(n^3)
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         string temp = s.substr(i,j-i+1);
    //         if(temp[0]=='1' and temp[temp.length()-1]=='1') count++;
    //     }
    // }

    // Method 2 O(n^2)
    // for(int i=0;i<n;i++){
    //     if(s[i]=='1'){
    //         for(int j=i+1;j<n;j++){
    //             if(s[j]=='1') count++;
    //         }
    //     }
    // }

    // Method O(n)
    int temp=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') temp++;
    }
    count=(temp*(temp-1))/2;
    return count;
}

int main(){

    string s="00100101";
    cout<<solve(s)<<endl;

return 0;
}