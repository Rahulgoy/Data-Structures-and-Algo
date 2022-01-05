#include <bits/stdc++.h>
using namespace std;
#define d 256 

void search(char pattern[],char text[], int prime){
    int p_len = strlen(pattern);
    int t_len = strlen(text);
    int p_hash=0, t_hash=0;
    int h=1;
    int i,j;

    for (i=0;i<p_len-1;i++){
        h = (h*d) % prime;
    }

    for(i=0;i<p_len;i++){
        p_hash = (d*p_hash + pattern[i]) % prime;
        t_hash = (d*t_hash + text[i]) % prime;
    }

    for(i=0;i<=t_len-p_len;i++){

        if(p_hash == t_hash){
            bool flag = true;

            for(j=0;j<p_len;j++){
                if(text[i+j]!=pattern[j]){
                    flag=false;
                    break;
                }
                // if(flag) cout<<i<<" ";
            }
            if (j == p_len) 
                cout<<"Pattern found at index "<< i<<endl;
        }

        if ( i < t_len-p_len ) 
        { 
            t_hash = (d*(t_hash - text[i]*h) + text[i+p_len])%prime; 
  
            // We might get negative value of t, converting it 
            // to positive 
            if (t_hash < 0) 
            t_hash = (t_hash + prime); 
        } 
    }
}


int main(){

    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";

    int prime = 101;

    search(pattern, text, prime);

    return 0;
}