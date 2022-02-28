#include <bits/stdc++.h>
using namespace std;

int solve(int i,int j, string s, char ch[6][6], int size,int idx){
    int found=0;

    if(i>=0 and j>=0 and i<6 and j<6 and s[idx]==ch[i][j]){
        char temp = s[idx];
        ch[i][j]=0;
        idx++;
        if(idx==size){
            found=1;
        }else{
            found += solve(i+1,j,s,ch,size,idx);
            found += solve(i-1,j,s,ch,size,idx);
            found += solve(i,j+1,s,ch,size,idx);
            found += solve(i,j-1,s,ch,size,idx);
        }
        ch[i][j]=temp;
    }
    return found;
}


int main(){

    string s="GEEKS";

    char ch[6][6] = {
        {'D','D','D','G','D','D'},
        {'B','B','D','E','B','S'},
        {'B','S','K','E','K','K'},
        {'D','D','D','G','S','E'},
        {'D','D','D','G','D','E'},
        {'D','D','D','D','D','G'},
    };
    int ans = 0;
    int size = s.length();
    // cout<<size<<endl;
    int l = sizeof(ch)/sizeof(ch[0]);
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            ans+=solve(i,j,s,ch,size,0);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}