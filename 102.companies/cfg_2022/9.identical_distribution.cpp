#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> cardTypes){
    int n=cardTypes.size();
    int i,d,ans=n,M=*max_element(cardTypes.begin(),cardTypes.end());    
    vector<int>cnt(M+1,0);

    for(i=0;i<n;i++)cnt[cardTypes[i]]++;

    int total=0;
    int s1=0;
    for(i=0;i<=M;i++){
        total+=cnt[i];
        s1+=i*cnt[i];
        cnt[i]=total;
    }
    
    for(d=2;d<=M;d++){
        int s=total*d-s1;
        for(i=0;i<=M&&s<ans;i+=d)
            s+=i*(cnt[min(i+d,M)]-cnt[i]);
        ans=min(ans,s);
    }
    return ans;

}


int main(){

    // vector<int> arr={3,8,7,6,4};
    vector<int> arr={4,7,5,11,15};
    cout<<solve(arr)<<endl;

return 0;
}