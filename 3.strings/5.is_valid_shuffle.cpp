#include <bits/stdc++.h>
using namespace std;

int is_valid(string first,string second, string results){
    if(first.length()+second.length()!=results.length()) return 0;

    int s1 = results.find(first);
    sort(results.begin(),results.end());
    cout<<results<<endl;
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());

    if(results.find(first)!= string::npos){
        if(results.find(second)!= string::npos) return 1;
    }
    return 0;
    
}

int main(){

    string first = "ACE";
    string second = "BD";
    string results = "BACDE";
    // "Y1X2", "Y21XX"
    if(is_valid(first,second,results)) cout<<"IS VALID"<<endl;
    else cout<<"Not VALID"<<endl;

return 0;
}


// Task is to check if two strings when combined together and may be shuffled give same result.
// Fails for given sub-task
//     string first = "ACE";
//     string second = "BD";
//     string results = "BACDE";


// The better approach would be to create two maps and count each character and compare them later.
