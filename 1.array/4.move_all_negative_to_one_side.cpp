#include <bits/stdc++.h>
using namespace std;

void moveneg(vector<int> &v){
    int n = v.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(v[i]<0){
            swap(v[i],v[j]);
            j++;
        }
    }
}

int main(){

    vector<int> v = {-4,-5,5,3,-4,9,-1,-2};

    moveneg(v);
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}