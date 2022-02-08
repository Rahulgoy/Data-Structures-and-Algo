#include <bits/stdc++.h>
using namespace std;
int minSwap(int arr[], int n, int k) {
        // Complet the function
        
        int cnt=0;
        //COUNTING GOOD VALUES
        for(int i=0;i<n;i++){
            if(arr[i] <= k)
                cnt++;
        }
        // COUNTING BAD VALUES IN FIRST K ELEMENTS
        int bad=0;
        for(int i=0;i<cnt;i++){
            if(arr[i]>k)
                bad++;
        }
        
        int i=0,j=cnt,ans=bad;
        while(j<n){
            //IF THE ELEMENT WENT OUT OF WINNDOW WAS BAD ELEMNT
            if(arr[i] > k)
                bad--;
            //IF THE NEW ELEMENT ENTERING IS BAD 
            if(arr[j] > k)
                bad++;
            //KEEPING MINIMUM BAD VALUES AS ANS
            ans=min(ans,bad);
            i++;j++;
        }
        //MINIMUM BAD VALUES = SWAPS WE REQUIRED
        return ans;
    }
int main(){


return 0;
}