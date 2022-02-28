#include <bits/stdc++.h>
using namespace std;

int countSetBits(int num){
        int count=0;
        while(num>0){
            num = num & (num-1);
            count++;
        }
        return count;
    }
    
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            int bits = countSetBits(arr[i]);
            res.push_back({arr[i],bits});
        }
        stable_sort(res.begin(),res.end(),comp);
        
        for(int i = 0;i<n;i++)
        {
            arr[i] = res[i].first;
        }
    }

int main(){

    int arr[]={5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;

return 0;
}