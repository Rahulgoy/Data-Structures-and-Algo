#include <bits/stdc++.h>
using namespace std;

bool check(int mid,int n){
           int cnt = 0, f = 5;
           while(f <= mid){
               cnt += mid / f;
               f *= 5;
           }
           return (cnt >= n);
       }
       
int findNum(int n){
    int s = 0, e = 5*n;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2 - ((s+e)/2)%5;
        if(check(mid,n)){
            ans = mid;
            e = mid - 5;
        }
        else s = mid + 5;
    }
    return (ans);
}

int main(){

    cout<<findNum(3)<<endl;
return 0;
}