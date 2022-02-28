// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
// Sample code to perform I/O:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findKSmallest(vector<pair<int,int>> &ranges, int n, vector<int> &targets,int q){
    sort(ranges.begin(),ranges.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++){

			int kth = ranges[i].first + targets[j]-1;
			if(kth>ranges[i].second) cout<<-1<<endl;
			else cout<<kth<<endl;

			// for(int k=ranges[i].first;k<=ranges[i].second;k++){

			// }
		}
		
	}
}

int main() {

	int t;
	cin>>t;
	while(t>0){
		int n,q;
		cin >> n>>q;
		
		int a,b;
		vector<pair<int,int>> ranges(n);
		for(int i=0;i<n;i++){
			cin>>a>>b;
			ranges[i].first = a;
			ranges[i].second = b;
		}

		vector<int> targets(q);
		for(int i=0;i<q;i++){
			cin>>targets[i];
		}

		findKSmallest(ranges,n,targets,q);
        t--;
	}

    return 0;
	
}
