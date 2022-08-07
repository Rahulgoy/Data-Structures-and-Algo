#include <bits/stdc++.h>

double multiply(double number,int n){
    double ans=1.0;
    while(n--){
        ans*=number;
    }
    return ans;
}
double findNthRootOfM(int n, int m) {
	// Write your code here.
    double low=1;
    double high=m;
    
    double eps=1e-9;
    
    while((high-low)>eps){
        double mid=(low+high)/2;
        if(multiply(mid,n)>m) high=mid;
        else low=mid;
        
    }
    return high;
}