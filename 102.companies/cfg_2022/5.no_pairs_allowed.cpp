#include <bits/stdc++.h>
using namespace std;

vector<int> noPairs(vector<string> arr){
    vector<int> res;
    
    for(int i=0;i<arr.size();i++){
        string temp = arr[i];
        int count=0;
        int n = temp.length();
        for(int j=0;j<n-1;j++){
            if(temp[j]==temp[j+1]){
                if(j+2<=n-1 and temp[j+1]==temp[j+2]){
                    count++;
                    j++;
                }else count++;
            }
        }
        cout<<count<<endl;
        res.push_back(count);
        
    }

    return res;
}

int main(){

    vector<string> arr={"ddooo","boook","break"};

    noPairs(arr);

return 0;
}