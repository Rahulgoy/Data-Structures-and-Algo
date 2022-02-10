#include <bits/stdc++.h>
using namespace std;

    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      set<int> hashset;
      for(int i=0;i<N;i++){
          hashset.insert(arr[i]);
      }
      
      int longestStreak=0;
      for(int i=0;i<N;i++){
          if(!hashset.count(arr[i]-1)){
              int currentNum = arr[i];
              int currentStreak = 1;
              
              while(hashset.count(currentNum+1)){
                  currentNum+=1;
                  currentStreak+=1;
                  
              }
              longestStreak = max(longestStreak,currentStreak);
          }
          
      }
      return longestStreak;
    }
int main(){

    // int arr[] = {9, 2, 3, 8, 4, 7, 6};
    int arr[] = {2,6,1,9,4,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findLongestConseqSubseq(arr,n)<<endl;

return 0;
}