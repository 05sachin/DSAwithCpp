/*Problem Description:
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i,  j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.*/

#include<iostream>
#include<climits>
using namespace std;

int minCostPath(int** arr ,int row ,int col, int i,int j){
    if(i==row-1 && j==col-1){
        return arr[i][j];
    }
    int cost = INT_MAX;
    if(i<row-1 && j<col-1){
        cost = min(cost,minCostPath(arr,row,col,i+1,j));
        cost = min(cost,minCostPath(arr,row,col,i,j+1));
        cost = min(cost,minCostPath(arr,row,col,i+1,j+1));
    }
    else if(j<col-1){
        cost = min(cost,minCostPath(arr,row,col,i,j+1));
    }
    else{
        cost = min(cost,minCostPath(arr,row,col,i+1,j));
    }
    return cost + arr[i][j];
      
    
}
int minCostPathMemo(int** arr ,int row ,int col, int i,int j,int** ans){
    if(i==row-1 && j==col-1){
        return ans[i][j]=arr[i][j];
    }
    if(ans[i][j]!=-1) return ans[i][j];
    int cost = INT_MAX;
    if(i<row-1 && j<col-1){
        cost = min(cost,minCostPathMemo(arr,row,col,i+1,j,ans));
        cost = min(cost,minCostPathMemo(arr,row,col,i,j+1,ans));
        cost = min(cost,minCostPathMemo(arr,row,col,i+1,j+1,ans));
    }
    else if(j<col-1){
        cost = min(cost,minCostPathMemo(arr,row,col,i,j+1,ans));
    }
    else{
        cost = min(cost,minCostPathMemo(arr,row,col,i+1,j,ans));
    }
    ans[i][j]=cost + arr[i][j];
    return ans[i][j];
      
    
}
int  minCostPath_1(int** arr ,int row ,int col, int i,int j){
    int** ans = new int*[row];
    for(int i=0;i<row;i++){
        ans[i] = new int[col];
        for(int j=0;j<col;j++){
            ans[i][j]=-1;
        }
    }
    return minCostPathMemo(arr,row,col,i,j,ans);
}
int minCostPath_2(int** arr ,int row,int col){
    int** ans = new int*[row+1];
    for(int i=0;i<=row;i++){
        ans[i] = new int[col+1];
        ans[i][col]=INT_MAX;
        if(i==row){
            for(int j=0;j<=col;j++){
               ans[row][j]=INT_MAX;
            }
        }
        
    }
    ans[row][col]=0;
    for(int i=row-1;i>=0;i--){
        for(int j = col-1;j>=0;j--){
           
            int  cost = ans[i+1][j];
            cost = min(cost,ans[i][j+1]);
            cost = min(cost,ans[i+1][j+1]);
            ans[i][j]=cost+arr[i][j];
            
        }
    }
    return ans[0][0];
    
}
int main(){
    int row;
    int col;
    cin>>row;
    cin>>col;
    int** arr = new int*[row];
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<minCostPath(arr,row,col,0,0)<<endl;
    cout<<minCostPath_1(arr,row,col,0,0)<<endl;
    cout<<minCostPath_2(arr,row,col)<<endl;
}