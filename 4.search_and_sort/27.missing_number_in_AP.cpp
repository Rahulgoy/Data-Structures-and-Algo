#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C){
        // code here
        // b = a+ (n-1)d;
        // n = (b-a)/c + 1;
       if(A==B)return 1;
       if(C==0 && A!=B || A<B && C<0 || A>B && C>0)return 0;
       if(A!=B && (B-A)%C==0)return 1;
       else return 0;
    }

int main(){

    cout<<inSequence(1,2,3)<<endl;
return 0;
}