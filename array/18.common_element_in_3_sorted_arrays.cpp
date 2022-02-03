#include <bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            // Method 1 O(n1+n2+n3) space complexity
            vector<int> res;
            unordered_map<int,int> m1;
            unordered_map<int,int> m2;
            unordered_map<int,int> m3;
            
            for(int i=0;i<n1;i++){
                m1[A[i]]++;
            }
            for(int i=0;i<n2;i++){
                m2[B[i]]++;
            }
            for(int i=0;i<n3;i++){
                m3[C[i]]++;
            }
            for(int i=0;i<n1;i++){
                if(m1[A[i]] and m2[A[i]] and m3[A[i]]){
                    res.push_back(A[i]);
                    m1[A[i]]=0;
                }
            }
            return res;





// M2
/* vector<int> res;
            int i=0,j=0,k=0;
            
            while(i<n1 and j<n2 and k<n3){
                
                if(A[i]==B[j] and B[j]==C[k]){
                    res.push_back(A[i]);
                    i++;j++;k++;
                }else if(A[i]<B[j]) i++;
                else if(B[j]<C[k]) j++;
                else k++;
                
                int x=A[i-1];
                while(A[i]==x) i++;
                int y=B[j-1];
                while(B[j]==y) j++;
                int z=C[k-1];
                while(C[k]==z) k++;
                
                
            }
            if(res.size()==0) return {-1};
            return res; */








        }




int main(){


return 0;
}

/* 
Time complexity O(n1+n2+n3)
Space Complexity O(n1+n2+n3)
 */