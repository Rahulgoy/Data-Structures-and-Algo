#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(mp[a2[i]]<1) return "No";
    }
    return "Yes";
}

int main(){

    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    cout<<isSubset(a1,a2,6,4)<<endl;

return 0;
}