// leetcode problem
#include <bits/stdc++.h>
using namespace std;

void fill(int i,int j,vector<vector<int>>& image,int m,int n,vector<vector<int>>& visited,int newColor,int orgColor){
        if(i<0 or j<0 or i>m-1 or j>n-1) return;
        if(image[i][j]!=orgColor or visited[i][j]==1) return;
        image[i][j] = newColor;
        visited[i][j]=1;
        fill(i+1,j,image,m,n,visited,newColor,orgColor);
        fill(i-1,j,image,m,n,visited,newColor,orgColor);
        fill(i,j-1,image,m,n,visited,newColor,orgColor);
        fill(i,j+1,image,m,n,visited,newColor,orgColor);
        visited[i][j]=0;
    }
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    fill(sr,sc,image,m,n,vis,newColor,image[sr][sc]);
    return image;
}

int main(){


return 0;
}