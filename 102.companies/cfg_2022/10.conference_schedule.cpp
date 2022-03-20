#include <bits/stdc++.h>
using namespace std;
int maxPresentations(vector<int> scheduleStart, vector<int> scheduleEnd)
{
    int n = scheduleStart.size();
    pair<int, int> a[n + 1];
    int i;
    for (i = 0; i < n; i++) {
        a[i].first = scheduleEnd[i];
        a[i].second = i;
    }
 
    sort(a, a + n);
 

    int time_limit = a[0].first;
 
    
    vector<int> m;
 

    m.push_back(a[0].second + 1);
 
  
    for (i = 1; i < n; i++) {
        if (scheduleStart[a[i].second] >= time_limit) {
   
            m.push_back(a[i].second + 1);
 
        
            time_limit = a[i].first;
        }
    }

    return m.size();
}

int main() {
	// your code goes here
    // vector<int> ss = {1,1,2,3} ;
    // vector<int> se = {2,3,3,4} ;

    vector<int> ss = {1,1,2} ;
    vector<int> se = {3,2,4} ;
    cout<<maxPresentations(ss,se) ;
	return 0;
}