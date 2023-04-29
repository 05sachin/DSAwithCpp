#include<iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int maxDistance(vector<vector<int>>& grid) {
        vector<int> fx={-1,1,0,0};
        vector<int> fy={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;
                }
            }
        }
        int l=0;
       
        if(q.empty() || q.size()==n*m) return -1;
        while(!q.empty()){
            int t=q.size();
            while(t--){
            auto p =q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int i= p.first+fx[k];
                int j=p.second+fy[k];
                if(i>=0 && i<n && j>=0 && j<m){
                    if(grid[i][j]==0){
                        q.push({i,j});
                        grid[i][j]=2;
                    }
                }

            }
            }
            l++;
            

            
        }
        return l-1;
    }
int main(){
    vector<vector<int>> grid={{1,0,1},{0,0,0},{1,0,1}};
    cout<<maxDistance(grid)<<endl;
}