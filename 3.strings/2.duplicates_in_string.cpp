#include <bits/stdc++.h>
using namespace std;


void printDups(char *strr){
    int len = sizeof(strr)/sizeof(strr[0]);
    unordered_map<char,int> m;
    for(int i=0;i<len;i++){
        m[strr[i]]++;
    }
    for (auto it : m) {   //iterating through the unordered map
        if (it.second > 1)   //if the count of characters is greater then 1 then duplicate found
            cout << it.first << ", count = " << it.second
                 << "\n";
    }

}

int main(){

    char strr[] = "test string";
    printDups(strr);
    return 0;
}