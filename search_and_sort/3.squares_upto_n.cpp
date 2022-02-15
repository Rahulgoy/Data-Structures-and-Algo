#include <bits/stdc++.h>
using namespace std;

int countSquares(int N) {
        // code here
        // M1
        int n = sqrt(N);
        int sq = n*n;
        if(sq==N) return n-1;
        return n;
        
        // M2
        return floor(sqrt(N-1));
    }

int main(){

    int n=10;
    cout<<countSquares(n)<<endl;

return 0;
}