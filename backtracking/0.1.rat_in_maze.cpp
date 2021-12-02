#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** mat,int x,int y, int n){
    if(x<n and y<n and mat[x][y]==1){
        return true;
    }
    return false;
}
bool ratinMaze(int** mat, int n,int x, int y, int** sol){
    if(x==n-1 and y==n-1){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(mat,x,y,n)){
        sol[x][y]=1;

        if(ratinMaze(mat,n,x+1,y,sol)){
            return true;
        }
        if(ratinMaze(mat,n,x,y+1,sol)){
            return true;
        }
        sol[x][y]=0;
        return false;
    }
}

int main(){

    int n;
    cin>>n;

    int** mat =new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    int** sol =new int*[n];
    for(int i=0;i<n;i++){
        sol[i] = new int[n];
        for(int j=0;j<n;j++){
            sol[i][j]=0;
        }
    }
    if(ratinMaze(mat,n,0,0,sol)){
        cout<<"Result\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
    }


    return 0;
}



// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1