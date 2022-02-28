#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> ar) {
    //Write your code here
    int n = ar.size();
    int i=0,j=n-1,oper=0;
    while(i<=j){
        if(ar[i]==ar[j]){
            i++;j--;
        }else if(ar[i]<ar[j]){
            i++;
            ar[i]+=ar[i-1];
            oper++;
        }else{
            j--;
            ar[j]+=ar[j+1];
            oper++;
        }
    }

    return oper;
}

int main(){

    vector<int> v={1,9,10,1};
    cout<<merge(v)<<endl;

return 0;
}