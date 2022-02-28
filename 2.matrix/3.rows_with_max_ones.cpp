// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ones=0,ind=0;
	    for(int i=0;i<n;i++){
	        int sum=0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1){
	                 sum+=m-j;
	                 break;
	            }
	        }
	        if(sum>ones){
	            ones=sum;
	            ind=i;
	        }
	    }
	    if(ones==0) return -1;
	    return ind;
	}


int main(){


return 0;
}