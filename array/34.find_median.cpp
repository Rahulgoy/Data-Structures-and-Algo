#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
		{
		    // Code here.
		    int n = v.size()-1;
		    sort(v.begin(),v.end());
		    if(n%2==0){
		        return v[(n/2)];
		    }else{
		        return (v[(n/2)]+v[(n/2)+1])/2;
		    }
		}

int main(){


return 0;
}