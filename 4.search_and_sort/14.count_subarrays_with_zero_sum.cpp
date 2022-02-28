#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll count=0;ll sum=0;
        unordered_map<ll,ll> mp;
        for(int i=0;i<n;i++){
            // if(arr[i]==0) count++;
            sum+=arr[i];
            if(sum==0) count++;
            count+=mp[sum];
            mp[sum]++;
        }
        return count;
    }

int main(){

    vector<ll> arr = {0,0,5,5,0,0};
    cout<<findSubarray(arr,arr.size())<<endl;

return 0;
}