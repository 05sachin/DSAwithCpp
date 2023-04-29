/*Chapter Assignment
Problem Statement: Maximum Square Matrix With All Zeros
Problem Level: MEDIUM
Problem Description:
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).

Output Format:
Print the size of maximum square sub-matrix.

Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec

Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1

Sample Output 1:
1

Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Sample Output 2:
4*/

#include<iostream>
using namespace std;
int maxSquareMatrixWithAllZeros(int** arr,int n,int m){
    int** dp = new int*[n+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[m+1];
        
    }
    int maxVal=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                if(arr[i][j]==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=0;
                }
                maxVal = max(maxVal,dp[i][j]);
                continue;
            }
            if(arr[i][j]==0){
                dp[i][j]= 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
            else{
                dp[i][j]=0;
            }
            maxVal = max(maxVal,dp[i][j]);
        }
    }
    return maxVal;
}
int main(){
    int n,m;
    cin>>n>>m;
    int** arr = new int*[n];
    

    for(int i=0;i<n;i++){
        arr[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxSquareMatrixWithAllZeros(arr,n,m)<<endl;
}