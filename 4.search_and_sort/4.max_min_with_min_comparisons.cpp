#include <bits/stdc++.h>
using namespace std;

vector<int> maxMin(vector<int> &v){
    int n = v.size();
    int max=INT_MIN;
    int min=INT_MAX;

    if(v[0]>v[1]){
        max = v[0];
        min = v[1];
    }else{
        max = v[1];
        min = v[0];
    }

    for(int i=2;i<n;i++){
        if(v[i]>max) max=v[i];
        else if(v[i]<min) min=v[i];
    }

    return {max,min};
}

int main(){

    vector<int> v = {5,9,8,1,2,3,5,4,8,5,6,7};
    vector<int> res=maxMin(v);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}