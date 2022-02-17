#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
        sort(a.begin(),a.end());
        
        if(n==m){
            return a[n-1]-a[0];
        }
        long long k=0;
        long long diff = INT_MAX;
        while(k+m-1<n){
            diff = min(diff,a[k+m-1]-a[k]);
            k++;
        }
        
        return diff;
    } 

int main(){

    vector<long long> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = 8;
    long long m = 5;

    cout<<findMinDiff(arr,n,m)<<endl;

return 0;
}