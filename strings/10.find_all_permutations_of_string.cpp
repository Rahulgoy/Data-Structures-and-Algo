#include <bits/stdc++.h>
using namespace std;

// Using STL
vector<string>find_permutation(string S)
{
		    // Code here there
		    vector<string> s;
             sort(S.begin(), S.end());  
             do
             {
                s.push_back(S);
             }while(next_permutation(S.begin(),S.end()));
             
        return s;
}




// Without using stl
vector<string> ans;
set<string> s;
void solve(string &S,int i){
    if(S[i]=='\0'){
        s.insert(S);
        return;
    }
    for(int j=i; S[j]!='\0';j++){
        swap(S[i],S[j]);
        solve(S,i+1);
        swap(S[i],S[j]);
    }
}
    
    
    
vector<string>find_permutation2(string S)
{
    // Code here there
    
    solve(S,0);
    for(auto c:s){
        ans.push_back(c);
    }
    return ans;
}


int main(){

    string S="ABC";
    // cin >> S;
    vector<string> ans = find_permutation(S);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    

return 0;
}