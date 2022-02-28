#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    
    for(int i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    
}

int main(){


return 0;
}