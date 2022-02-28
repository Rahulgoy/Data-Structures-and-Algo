#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int> &v1,vector<int> &v2){

    int n1 = v1.size();
    int n2 = v2.size();

    vector<int> res(n1+n2);

    int i=0,j=0,k=0;
    while(i<n1 and j<n2){
        if(v1[i]<v2[j]){
            res[k]=v1[i];
            i++;k++;
        }else if(v1[i]>v2[j]){
            res[k]=v2[j];
            j++;k++;
        }else{
            res[k]=v1[i];
            k++;i++;
            res[k]=v2[j];
            k++;j++;
        }
    }
    while(i<n1){
        res[k]=v1[i];
        i++;k++;
    }
    while(j<n2){
        res[k]=v2[j];
        j++;k++;
    }

    for(int m=0;m<k;m++){
        cout<<res[m]<<" ";
    }
    cout<<endl;
    if((k+1)%2==0){
        return res[(k)/2];
    }else{
        return (res[((k)/2)]+res[((k)/2)-1])/2;
    }
}

int main(){

    // vector<int> v1 = {2, 3, 5, 8};
    // vector<int> v2 = {10, 12, 14, 16, 18, 20};


    vector<int> v1 = {-5, 3, 6, 12, 15};
    vector<int> v2 = {-12, -10, -6, -3, 4, 10};
    
    
    cout<<findMedian(v1,v2)<<endl;


return 0;
}