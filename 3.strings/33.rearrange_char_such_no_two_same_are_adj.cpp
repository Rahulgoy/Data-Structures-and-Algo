// https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/#

#include <bits/stdc++.h>
using namespace std;


// If we only had to tell if it is possible to rearrange
/* 
int rearrangeString(string str)
{
    //code here
    unordered_map<char,int> m;
    int n = str.length();
    int max=-1;
    for(int i=0;i<n;i++){
        m[str[i]]++;
        if(m[str[i]]>max) max=m[str[i]];
    }
    
    if(max<=n-max+1) return 1;
    return 0;
} */

string rearrangeString(string str)
{
    //code here
    int n = str.size();
    map<char, int> m;
    
    for(auto& ch: str){
        m[ch]++;
    }
    priority_queue<pair<int,char>> pq;
    
    for(char ch='a'; ch<='z'; ch++) {
        if(m.find(ch)!=m.end()) {
            if(m[ch]>(n+1)/2) return "-1";
            pq.push({m[ch], ch});
        }
    }
    
    string ans = "";
    
    while(!pq.empty()){
        //cout << top.first << " " << top.second << "\n";
        pair<int, char> top1 = pq.top();   // returns one with maximum value
        pq.pop();
        ans = ans+top1.second;
        top1.first--;
        
        if(!pq.empty()){
            pair<int, char> top2 = pq.top();
            pq.pop();
            ans = ans+top2.second;
            top2.first--;
            
            if(top2.first>0) pq.push(top2);
        }else if(top1.first>0) return "-1";
        
        if(top1.first>0) pq.push(top1);
        
    }
    return ans;
}




int main(){

    string s="aaabc";

    cout<<rearrangeString(s)<<endl;

return 0;
}

// O(nlog(n)) Time complexity
// O(number of letters) space complexity


/* 
General Algo
1. Create a map for all the characters in string
2. Create a priority queue for each correspondin character in map and its count
3. Pop the top element(having highest value) and place it first 
4. Now take out the second most valued string and place after the first.

a c _ _ _ 
_ _ _ _ _


 */ 