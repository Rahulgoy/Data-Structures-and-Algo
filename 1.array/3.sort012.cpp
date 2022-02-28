#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
    {
        // coode here 
        int zero=0,one=0,two=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) zero++;
        else if(arr[i]==1) one++;
        else two++;
    }
    
    for(int i=0;i<n;i++){
        if(i<zero){
            arr[i]=0;
        }
        else if(i>=zero and i<zero+one) arr[i]=1;
        else arr[i]=2;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }


int main(){

    int arr[] = {0,2,2,1,1,0,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    sort012(arr,n);

return 0;
}