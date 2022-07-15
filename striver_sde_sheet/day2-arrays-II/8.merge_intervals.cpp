class Solution {
public:
    static bool comp(const vector<int>&x , const vector<int> &b){
        return x[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        if(n==1) return intervals;
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        for(int i=1;i<n;i++){
            vector<int> tmp = st.top();
            if(tmp[1]>=intervals[i][0]){
                st.pop();
                st.push({min(tmp[0],intervals[i][0]),max(tmp[1],intervals[i][1])});
                
            }else{
                st.push(intervals[i]);
            }
        }
        vector<vector<int>> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};