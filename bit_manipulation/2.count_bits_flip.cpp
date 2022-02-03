#include <bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b){
        
       int a_xor_b = a ^ b;
       //  a = 5(00000101), b = 9(00001001)
       //  a^b = 00001100 = 12
       cout<<a_xor_b<<endl;
       int count = 0;
       
       while(a_xor_b){
           a_xor_b &= a_xor_b - 1; // removes the least significant bit 1.  ex- a=111 => a&a-1 = 110,  a=101100 then a&(a-1) = 101000
           count++;
       }
        
        return count;
    }

int main(){

    cout<<countBitsFlip(5,9)<<endl;

return 0;
}