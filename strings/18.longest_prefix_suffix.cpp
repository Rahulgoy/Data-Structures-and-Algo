#include <bits/stdc++.h>
using namespace std;

int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    vector<int> arr(n,0);
	    
	    int j=0,i=1;
	    
	    while(i<n){
	        if(s[i]==s[j])
	        {
	            arr[i] = j+1;
	            j++;i++;
	        }else{
	            if(j==0) i++;
	            else j=arr[j-1];
	        }
	    }
	    return arr.back();
}

int main(){

    string s="aaaa";
    cout<<lps(s);
    return 0;
}

// O(s) time and space complexity