// Using minimum number of operations

#include <bits/stdc++.h>
using namespace std;


void findminmax(vector<int> v){
    int min=INT_MAX, max=INT_MIN;

    int n = v.size();

    if(v[0]>v[1]){
        max=v[0];
        min=v[1];
    }else{
        max=v[1];
        min=v[0];
    }

    for(int i=2;i<n;i++){
        if(v[i]>max) max=v[i];
        if(v[i]<min) min=v[i];
    }

    cout<<max<<" "<<min<<endl;

}



int main(){

    vector<int> v = {5,6,4,1,2,9,8,3};

    findminmax(v);


return 0;
}