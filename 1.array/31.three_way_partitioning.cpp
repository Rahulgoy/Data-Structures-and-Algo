#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        // Method 1
        // sort(array.begin(),array.end());
        
        // Method 2
        int n = array.size();
        int low=0,high=n-1,mid=0;
        while(mid<=high){
            if(array[mid]<a){
                swap(array[low],array[mid]);
                low++;
                mid++;
            }else if(array[mid]>=a and array[mid]<=b) mid++;
            else{
                swap(array[high],array[mid]);
                high--;
            }
        }
        
        
    }

int main(){

vector<int> v={2,9,3,4,1,6,8,5,2};
threeWayPartition(v,4,6);
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
} 
return 0;
}
// 2 3 1 4 2 6 8 5 9
// low =  3
// mid =  5
// high = 7