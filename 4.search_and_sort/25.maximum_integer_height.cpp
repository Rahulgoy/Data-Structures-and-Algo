#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Method 1 Brute Force O(n^2)
// int maxHeight(vector<int> &heights,int n, int wood){
	
// 	int mini=INT_MAX,maxi=INT_MIN;
// 	maxi = *max_element(heights.begin(),heights.end());
// 	mini = *min_element(heights.begin(),heights.end());
// 	int max_sum=0,max_height=0;
// 	for(int i=mini;i<=maxi;i++){
// 		int sum=0;
// 		for(int j=0;j<n;j++){
// 			if(heights[j]>=i){
// 				sum += heights[j]-i;
// 				if(sum>=wood){
// 					max_height=max(max_height,i);
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	return max_height;
// }

bool solve(vector<int> &heights,int n,int wood,int mid){

    int sum=0;
    for(int i=0;i<n;i++){
        if(heights[i]>=mid){
            sum += heights[i]-mid;
            if(sum>=wood){
                return true;
            }
        }
        
    }
    return false;

}

// Method 2 Binary Search O(nlogn(n))
int maxHeight1(vector<int> &heights,int n, int wood){

    int low=0,high=INT_MIN;
	high = *max_element(heights.begin(),heights.end());
	int max_height=0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(solve(heights,n,wood,mid)){
            max_height=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return max_height;

}

int main() {
	// your code goes here
	
	int n,wood;
	cin>>n>>wood;
	
	vector<int> heights(n);
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	
	cout<<maxHeight1(heights,n,wood);
	return 0;
}

/* 
Sample Input
4 7 
20 15 10 17
Output : 15

Input
5 20
4 42 40 26 46
Output: 36
 */