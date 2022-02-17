// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
// Sample code to perform I/O:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void numAndPow(vector<int> &powers,int n,vector<int> &rounds,int q){
	sort(powers.begin(),powers.end());
	for(int i=0;i<q;i++){
		int sum=0,count=0;
        // cout<<endl<<"Round  "<<rounds[i];
        int j=0;
		for(j=0;j<n;j++){
			if(powers[j]<=rounds[i]){
				count++;
				sum+=powers[j];
			}else{
				// cout<<endl;
                cout<<count<<" "<<sum<<endl;
				break;
			}
		}
        if(j==n){
            // cout<<endl;
            cout<<count<<" "<<sum<<endl;
        }
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> powers(n,0);
	for(int i=0;i<n;i++){
		cin>>powers[i];
	}
	int q;
    cin>>q;
	vector<int> rounds(q,0);
	for(int i=0;i<q;i++){
		cin>>rounds[i];
	}

	numAndPow(powers,n,rounds,q);
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
/* 
Sample Input
7
1 2 3 4 5 6 7
3
3
10
2

Sample Output
3 6
7 28
2 3

 */