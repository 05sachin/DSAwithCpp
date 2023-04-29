/*Chapter Assignment
Problem Statement: Largest Piece
Problem Level: MEDIUM
Problem Description:
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1

Sample Output 1:
3
*/

#include<iostream>
#include<climits>
using namespace std;
int dfs(int** input,int i,int j,bool** temp,int n){
    if(i<0 || i>=n || j<0 || j>=n){
        return 0;
    }
    if(input[i][j]==0) return 0;
    if(temp[i][j]) return 0;
    temp[i][j]=true;
    int ans = 1+dfs(input,i+1,j,temp,n)+dfs(input,i-1,j,temp,n)+dfs(input,i,j+1,temp,n)+dfs(input,i,j-1,temp,n);
    return ans;

    
}
int largestPiece(int** input,int n){
    bool** temp = new bool*[n];
    for(int i=0;i<n;i++){
        temp[i]=new bool[n];
        for(int j=0;j<n;j++){
            temp[i][j]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            if(!temp[i][j] && input[i][j]==1){
                ans=max(ans,dfs(input,i,j,temp,n));
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    int** input = new int*[n];

    for(int i=0;i<n;i++){
        input[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }
    cout<<largestPiece(input,n)<<endl;
}