#include <bits/stdc++.h>
using namespace std;

int setbits(int n){
    int count=0;
    while(n>1){
        if(n%2!=0) count++;
        n=n/2;
    }
    return count+1;
}

int main(){

    int n = 8;
    cout<<setbits(n)<<endl;

return 0;
}