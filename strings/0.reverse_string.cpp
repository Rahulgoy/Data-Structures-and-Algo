#include <bits/stdc++.h>
using namespace std;

// vector<char> reverse_str(vector<char> str){
//     int length = sizeof(str);
//     for(int i=0;i<length/2;i++){
//         char temp = str[i];
//         str[i]=str[length-i-1];
//         str[length-i-1]=str[i];
//     }
//     return str;
// }

// int main(){

//     vector<char> str;
//     str.push_back('h');
//     str.push_back('e');
//     str.push_back('l');
//     str.push_back('l');
//     str.push_back('o');

//     for(int i=0;i<sizeof(str);i++){
//         cout<<str[i]<<" ";
//     }
    

//     str = reverse_str(str);
//     for(int i=0;i<sizeof(str);i++){
//         cout<<str[i]<<" ";
//     }
//     return 0;
// }


string rev_str(string s){
    int length = s.length();
    // cout<<length<<endl;

    for(int i=0;i<length/2;i++){
        char temp = s[i];
        s[i]=s[length-i-1];
        s[length-i-1]=temp;
    }

    return s;
}


int main(){
    string s="testingreverse";
    cout<<s<<endl;

    s = rev_str(s);
    cout<<s<<endl;
    
}



//Leetcode
/* void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=0;i<len/2;i++){
            // char temp = s[i];
            // s[i]=s[len-i-1];
            // s[len-i-1]=temp;
            
            swap(s[i],s[len-i-1]);
        }
    } */