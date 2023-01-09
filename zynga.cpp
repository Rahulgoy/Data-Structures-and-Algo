#include <bits/stdc++.h>
using namespace std;

int main(){

    string s="creepfe";
    unordered_map<int,int> mp;
    
    for(int i=0;i<s.length();i++){
        cout<<s[i]<<" ";
        mp[int(s[i])]++;
        cout<<int(s[i])<<" ";

        if(mp[int(s[i])]>1){
            int temp=int(s[i])+1;
            s[i]=char(temp);
            cout<<endl<<s[i]<<" "<<temp<<" ";
            mp[temp]++;
            mp[int(s[i])]--;
        }


        // while(mp[s[i]-'a']>1){

        //     char temp=s[i]-'b';
        //     mp[temp]++;
        //     mp[s[i]-'a']--;
        // }
    }
    
    cout<<s<<endl;

return 0;
}