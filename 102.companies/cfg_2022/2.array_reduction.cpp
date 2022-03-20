#include <bits/stdc++.h>
using namespace std;

int reductionCost(vector<int> v){
    int n = v.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }
    // cout<<pq.size()<<endl;
    // cout<<pq.top()<<endl;
    int elem1,elem2;
    int res_sum=0;
    while(!pq.empty()){
        elem1=pq.top();pq.pop();
        // cout<<elem1<<endl;
        if(!pq.empty()){
            elem2=pq.top();pq.pop();
        }else break;
        // cout<<elem2<<endl;
        int sum = elem1+elem2;
        res_sum+=sum;
        pq.push(sum);
    }
    // res_sum+=elem1;
    return res_sum;
}

int main(){

    // vector<int> num={4,6,8};
    vector<int> num={2,2,5,3};
    cout<<reductionCost(num)<<endl;

return 0;
}