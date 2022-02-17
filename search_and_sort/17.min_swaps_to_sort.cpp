#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int> mp;
	    int n = nums.size();
	    for(int i=0;i<n;i++){
	        mp[nums[i]]=i;
	    }
	    sort(nums.begin(),nums.end());
	    int swaps=0;
	    for(int i=0;i<n;){
	        if(mp[nums[i]]!=i){
	            swap(nums[i],nums[mp[nums[i]]]);
	            swaps++;
	        }else i++;
	    }
	    return swaps;
	    
	    
	    // Code here  using pair
	   // int n = nums.size();
	   // vector<pair<int,int>> v;
	   // for(int i=0; i<n; i++){
	   //     v.push_back({nums[i],i});
	   // }
	   // sort(v.begin(),v.end());
	   // int swaps = 0;
	   // for(int i=0; i<n; i++){
	   //     int num = v[i].first;
	   //     int idx = v[i].second;
	   //     if(i!=idx){
	   //         //not in position
	   //         swaps += 1;
	            
	   //         swap(v[i],v[idx]);
	   //         i -= 1;
	   //     }
	   // }
	   // return swaps;
	}

int main(){


return 0;
}