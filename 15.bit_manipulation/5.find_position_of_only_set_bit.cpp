#include <bits/stdc++.h>
using namespace std;

int findPosition(int N) {
        // code here
        if((N & (N-1))!=0) return -1;
        if(N==0) return -1;
        int i=0;
        while(N>0){
            i++;
            if(N%2!=0) return i;
            N=N/2;
            
        }
        return i;
    }

int main(){


return 0;
}