// https://practice.geeksforgeeks.org/problems/next-permutation5226/1
#include <bits/stdc++.h>
using namespace std;

// Lexicographical order is the next highest possible value after rearrangement.

vector<int> nextPermutation(int N, vector<int> arr){
        
        int ind1=-1,ind2=-1;
        for(int i=0;i<N-1;i++){
            if(arr[i]<arr[i+1]){
                ind1=i;
            }
        }
        if(ind1==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                if(arr[i]<arr[j]){
                    ind2=j;
                }
            }
        }
        swap(arr[ind1],arr[ind2]);
        
        sort(arr.begin()+ind1+1, arr.end());
        // code here
        // next_permutation(arr.begin(),arr.end());
        return arr;
    }
int main(){

    vector<int> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    v = nextPermutation(N,v);
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
return 0;
}


/// Using STL  next_permutation(arr.begin(),arr.end());
//Time O(N) space O(1)

/* 
Input: N = 6
arr = {1, 2, 3, 6, 5, 4}

Output: {1, 2, 4, 3, 5, 6}
 */