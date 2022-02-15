#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int m=n;m>j+1;m--){
                    if((arr[i]+arr[j]+arr[m]+arr[m-1])==k){
                        // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[m]<<" "<<arr[m-1]<<endl;
                        vector<int> temp(4);
                        temp[0] = arr[i];
                        temp[1] = arr[j];
                        temp[2] = arr[m];
                        temp[3] = arr[m-1];
                        
                        sort(temp.begin(),temp.end());
                        vector< vector<int> >::iterator it = find(res.begin(), res.end(), temp);
                        bool isPresent = ( it != res.end() );
                        if(!isPresent){
                            res.push_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }

int main(){

    vector<int> arr = {0,0,2,1,1};
    int k = 3;

    vector<vector<int>> ans = fourSum(arr,k);
    for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << endl;
        }

return 0;
}






