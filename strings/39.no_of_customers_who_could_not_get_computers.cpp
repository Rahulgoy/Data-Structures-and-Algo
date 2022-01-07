#include <bits/stdc++.h>
using namespace std;

int CustomersAvail(int c,string s){
    int n = s.length();

    int count=0,res=0;
    int chr[256]={0};

    for(int i=0;i<n;i++){
        if(chr[s[i]]==0){
                chr[s[i]]++;
                if(count<c){
                    count++;
                    chr[s[i]]=2;
                }else res++;
        }else{
            if(chr[s[i]]==2) count--;
            chr[s[i]]=0;
        }

    }
    return res;
}

int main(){

    int c=1;
    string s="ABCBCA";

    cout << CustomersAvail(2, "ABBAJJKZKZ") << endl;
    cout << CustomersAvail(3, "GACCBDDBAGEE") << endl;
    cout << CustomersAvail(3, "GACCBGDDBAEE") << endl;
    cout << CustomersAvail(1, "ABCBCA") << endl;
    cout << CustomersAvail(1, "ABCBCADEED") << endl;
    return 0;
}