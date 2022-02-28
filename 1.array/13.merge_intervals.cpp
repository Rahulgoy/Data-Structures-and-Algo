// https://leetcode.com/problems/merge-intervals/submissions/
#include <bits/stdc++.h>
using namespace std;

static bool comp(const vector<int> &x, const vector<int> &b){
        return x[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res;
        if(n==1) return intervals;
        
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        for(int i=1;i<n;i++){
            vector<int> temp = st.top();
            if(temp[1]>=intervals[i][0]){
                vector<int> tmp;
                tmp.push_back(min(temp[0],intervals[i][0]));
                tmp.push_back(max(intervals[i][1],temp[1]));
                // intervals[i]=tmp;
                st.pop();
                st.push(tmp);
            }else{
                st.push(intervals[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
        
        
    }

int main(){


return 0;
}

/* 
Sample Inputs
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[0,2],[3,5]]

Outputs
[[1,6],[8,10],[15,18]]
[[0,5]]
 */