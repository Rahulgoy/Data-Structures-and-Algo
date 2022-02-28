#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1,string s2){
    int l1 = s1.length();
    int l2 = s2.length();

    if(l1!=l2) return 0;

    string temp = s1+s2;
    return (temp.find(s2) != string::npos);
}

int main(){

    string str1 = "ABCD", str2 = "CDAB";

    if(isRotation){
        cout<<"Is Rotation"<<endl;
    }else cout<<"Not Rotation"<<endl;
    
    return 0;
}

// Time complexity of find() function is O(logn) and that is of this code as well
// Space O(1)

// The other method that can be used is to create two queues and push each character of string in each queue respectively.
// Compare two queue ie q2==q1 by remove the first element and adding at last in q1after each iteration.