#include <bits/stdc++.h>
using namespace std;


string longestPalin (string S) {
        // code here
        int size=S.size();
        int  l,h;
        int start=0,end=1;
        for(int i=0;i<size;i++){
            l=i-1;
            h=i;
            while(l>=0 && h<size && S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
            l=i-1;
            h=i+1;
            while(l>=0 && h<size && S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
        
        }
            string temp=S.substr(start,end);
            return temp;
        
        
    }


int main(){

    string s = "aaaabbaa";
    cout<<longestPalin(s)<<endl;

return 0;
}