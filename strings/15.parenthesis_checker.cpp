#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        int n = x.length();
        int i=0;
        for(i=0;i<n;i++){
            if(x[i]=='(' or x[i]=='[' or x[i]=='{'){
                st.push(x[i]);
                continue;
            }
            
            if(st.empty()) return false;
            
            char c = st.top();
            if(c=='(' && x[i]==')' || c=='{' && x[i]=='}' || c=='[' && x[i]==']')
            {
                st.pop();
                
            }else return false;
        
        }
        if(st.empty()) return true;
        // if(!st.empty() and i==n) return false;
        
        return false;
    }

int main(){

    string x="{[(]}";
    cout<<ispar(x)<<endl;
return 0;
}

// Time complexity O(x)
// Space complexity O(x)