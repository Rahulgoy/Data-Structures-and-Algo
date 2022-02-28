#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        // Using a+b+c = x so a+b = x-c
        unordered_set<int> sums;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n-1;j++) sums.insert(A[i]+A[j]);
           if(sums.find(X-A[i]) != sums.end()) return true;
       }
       return false;
    }
int main(){

    int arr[] = {1, 4, 45, 6, 10, 8};
    cout<<find3Numbers(arr,6,13)<<endl;

return 0;
}