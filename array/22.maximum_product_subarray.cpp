#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	    // code here

	    long long max_product=arr[0],maxi=arr[0],mini=arr[0];
	    for(int i=1;i<n;i++){
	        if(arr[i]<0){
	            swap(maxi,mini);
	        }
	        if(arr[i]==0){
	            maxi=mini=1;
	        }else{
	        maxi = max(maxi*arr[i],(long long) arr[i]);
	        mini = min((long long) arr[i],mini*arr[i]);
	        }
	        max_product = max(max_product,maxi);
	    }
	    return max_product;
	}


int main(){


return 0;
}