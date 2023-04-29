#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
    public:
    int solve(vector<vector<int>>& grid,int i,int j) {
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        int ans=INT_MAX;

        if(i==grid.size()-1){
            ans=min(ans,solve(grid,i,j+1));
        }
        else if(j==grid[0].size()-1){
            ans=min(ans,solve(grid,i+1,j));
        }else{
            ans=min(ans,solve(grid,i,j+1));
            ans=min(ans,solve(grid,i+1,j));
        }
        return grid[i][j]+ans;
    }
    int solveM(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp) {
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;

        if(i==grid.size()-1){
            ans=solveM(grid,i,j+1,dp);
        }
        else if(j==grid[0].size()-1){
            ans=solveM(grid,i+1,j,dp);
        }else{
            int ans1=solveM(grid,i,j+1,dp);
            int ans2=solveM(grid,i+1,j,dp);
            ans=min(ans1,ans2);
        }
        return dp[i][j]=grid[i][j]+ans;
    }
    int solveTab(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i][m-1]=grid[i][m-1];
            }else{
                dp[i][m-1]=dp[i+1][m-1]+grid[i][m-1];
            }
            
        }
        for(int j=m-1;j>=0;j--){
            if(j==m-1){
                dp[n-1][j]=grid[n-1][j];
            }else{
                dp[n-1][j]=dp[n-1][j+1]+grid[n-1][j];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int ans = min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=grid[i][j]+ans;
            }
        }
        
        
        return dp[0][0];
    }
    int minPathMemo(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solveM(grid,0,0,dp);
        
    }
    
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8},{6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4},{7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4},{9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9},{1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4},{3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2},{1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3},{5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7},{2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7},{0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}};
     cout<<s.solveTab(grid)<<endl;
     cout<<s.solve(grid,0,0)<<endl;

    cout<<s.minPathMemo(grid)<<endl;
   

}