#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
        
        // Your code here  
        if(n==0 or n==1) return false;
        while(n>1){
            if(n%2==1) return false;
            n=n/2;
        }
        
        return true;
        
        // Method 2
        // return n&(n-1)==0?true:false;    this works because for power of 2 there is only 1 bit so we remove the 1 and it becomes all zero.
    }

int main(){


return 0;
}