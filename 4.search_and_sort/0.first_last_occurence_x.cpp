#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    // code here
    // if(*lower_bound(arr,arr+n,x)!=x)
    //     return {-1,-1};
    // int count=0,start=0,end=0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==x){
    //         if(count==0){
    //             start=i;
    //             end=i;
    //         }else end=i;
    //         count++;
    //     }
    // }
    // return {start,end};
    
    // M2 Using stl
    if(*lower_bound(arr,arr+n,x)!=x)
        return {-1,-1};

    return {(int)(lower_bound(arr,arr+n,x)-arr),(int)(upper_bound(arr,arr+n,x)-arr)-1};
    // bool isPresent = binary_search(arr,arr + n, x);
    // if(!isPresent) return{-1,-1};
    
}
int main(){

    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> res = find(arr,n,5);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

return 0;
}