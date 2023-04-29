/*Chapter Assignment
Problem Statement: Longest Increasing Subsequence
Problem Level: MEDIUM
Problem Description:
Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces

Output Format
Line 1 : Length of longest subsequence

Input Constraints
1 <= n <= 10^3

Sample Input :
6
5 4 11 1 16 8

Sample Output 1 :
3

Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2:
3
1 2 2

Sample Output 2 :
2
*/

#include<iostream>
using namespace std;
int longestIncreasingSubsequence(int* arr,int n,int i,int pre){
    if(i>=n){
        return 0;
    }
    
    int ans=0; 
    if(arr[i]>pre){
        ans+=longestIncreasingSubsequence(arr,n,i+1,arr[i])+1;
    }
    ans=max(ans,longestIncreasingSubsequence(arr,n,i+1,pre));
    
    return ans;
}
int longestIncreasingSubsequenceMemo(int* arr,int n,int i,int preInd,int** dp){
    if(i>=n){
        return dp[i][preInd+1]=0;
    }
    if(dp[i][preInd+1]!=-1){
        return dp[i][preInd+1];
    }
    int ans=0;
    if(preInd==-1 || arr[i]>arr[preInd]){ // take
        ans+=longestIncreasingSubsequenceMemo(arr,n,i+1,i,dp)+1;
    }
    ans=max(ans,longestIncreasingSubsequenceMemo(arr,n,i+1,preInd,dp));// non take
    
    return dp[i][preInd+1]=ans;
}

int longestIncreasingSubsequence_1(int* arr,int n){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+2];
        for(int j=0;j<=n+1;j++){
            dp[i][j]=-1;
        }
    }
    return longestIncreasingSubsequenceMemo(arr,n,0,-1,dp);
}
int longestIncreasingSubsequenceTab(int* arr,int n){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        dp[i][n]=0;
        if(i<n){
            continue;;
        }
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int len=0;
            if(j==-1 || arr[i]>arr[j]){
                len=1+dp[i+1][i+1];
            }
            dp[i][j+1]=max(len,dp[i+1][j+1]);
        }
    }
    return dp[0][0];
    
}

// easy solution 

int longestIncreasingSubsequence_3(int* arr,int n){
    int output[n];
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                continue;
            }
            int possibleAns =output[j]+1;
            if(possibleAns > output[i]){
                output[i]=possibleAns;
            }

        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,output[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestIncreasingSubsequence_1(arr,n)<<endl;
    cout<<longestIncreasingSubsequenceTab(arr,n)<<endl;
    cout<<longestIncreasingSubsequence(arr,n,0,-1)<<endl;
    cout<<longestIncreasingSubsequence_3(arr,n)<<endl;
}