#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n) {
	    // code here
	    vector<int> positive;
	    vector<int> negative;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0) positive.push_back(arr[i]);
	        else negative.push_back(arr[i]);
	    }
	    int j=0,k=0,i=0;
	    while(j<positive.size() and k<negative.size()){
	        if(i%2==0){
	            arr[i]=positive[j];
	            j++;i++;
	        }else{
	            arr[i] = negative[k];
	            k++;i++;
	        }
	    }
	    while(j<positive.size()){
	        arr[i]=positive[j];
	        j++;i++;
	    }
	    while(k<negative.size()){
	        arr[i]=negative[k];
	        k++;i++;
	    }
	}

int main(){


return 0;
}