// Do again https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

#include <bits/stdc++.h>
using namespace std;

/* string smallestWindow (string s, string p)
    {
        unordered_map<char,int>mp1,mp2;
       int start =0;
       
       for(int i=0;i<p.length();i++)
         mp1[p[i]]++;
         
         int des_count = p.length();
         int count1=0;
         int i=0,j=0;
         int res = INT_MAX;
         
         while(i<=j and j < s.length())
         {
             if(count1<des_count)
             {
                 mp2[s[j]]++;
                 if(mp2[s[j]] <= mp1[s[j]]) count1++;
                 
                 j++;
             }
             else if(count1 == des_count)
             {
                if(res!=j-i and res>j-i){
               //   res = min(res,j-i);
                       res =j-i;
                       start =i;
                 }
                  
                 mp2[s[i]]--;
                 if(mp2[s[i]]<mp1[s[i]] and mp2[s[i]]>=0)
                   count1--;
                  
                   i++;
             }
         }
         
         
       while(count1 == des_count)
       {        
                 if(res!=j-i and res>j-i){
               //   res = min(res,j-i);
               res =j-i;
                 start =i;
                 }
                  mp2[s[i]]--;
                 if(mp2[s[i]]<mp1[s[i]] and mp2[s[i]]>=0)
                   count1--;
                  
                   i++;
       }
       
       return res!=INT_MAX?s.substr(start,res):"-1";
        }
 */

string smallestWindow (string s, string p)
    {
        unordered_map<char , int> umap ;
        for(auto ch : p)
        umap[ch]++ ;
        
        int cnt = umap.size() ;
        
        int i = 0 ,j = 0 ;
        int n = s.size() ;
        int res = INT_MAX; 
        int start ; 
        while(j<n) 
        {
            if(umap.find(s[j]) != umap.end())
            {
                umap[s[j]]-- ;
                if(umap[s[j]] == 0)
                cnt-- ;
            }
            if(cnt>0)
            j++ ;
            else if(cnt == 0)
            {
               if(res > j-i+1)
               {
                   res = j-i+1 ;
                   start = i ;
               }
                
                while(cnt == 0)
                {
                    if(umap.find(s[i]) != umap.end())
                    {
                        umap[s[i]]++;
                        if(umap[s[i]] == 1)
                        {
                         cnt++;
                         if(res>j-i+1)
                         {
                            res = j-i+1 ;
                            start = i ;
                         }
            
                        }
                    }
                     i++;
                }
                    
                j++;
            }
             
        }
        string ans = "";
        if(res!=INT_MAX)
            return ans+= (s.substr(start,res));
        else
            return "-1";
    }



int main(){

    string s = "timetopractice";
    string p = "toc";

    cout<<smallestWindow(s,p)<<endl;

return 0;
}