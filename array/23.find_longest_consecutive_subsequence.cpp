#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      priority_queue<int> pq;
      for(int i=0;i<N;i++){
          pq.push(arr[i]);
      }
    //   cout<<pq.size()<<endl;
      int maxi=0,count=1,last_elem;
      while(!pq.empty()){
          int first,second;
          first = pq.top();pq.pop();
        //   cout<<first<<endl;
          if(pq.empty()){
              if(last_elem==first+1) count++;
              maxi = max(maxi,count);
              break;
          }
          
          second = pq.top();pq.pop();
          if(first==second+1){
              count++;
              maxi = max(maxi,count);
          }else{
              count=0;
          }
          last_elem=first;
          pq.push(second);
      }
      
      return maxi;
    }

int main(){

    // int arr[] = {9, 2, 3, 8, 4, 7, 6};
    int arr[] = {2,6,1,9,4,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findLongestConseqSubseq(arr,n)<<endl;

return 0;
}