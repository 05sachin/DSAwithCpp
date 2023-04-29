/*Chapter Assignment
Problem Statement: Shortest Subsequence
Problem Level: MEDIUM
Problem Description:
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Sample Input :
babab
babba

Sample Output :
3
*/

#include<iostream>
#include<climits>
using namespace std;
int shortestSubsequence(string s,string v){
    int n = s.length();
        int m = v.length();
        int** dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[m+1];
            dp[i][m]=1;
        }
        for(int i=0;i<=m;i++){
            dp[n][i]=501;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                int k=j;
                for(;k<m;k++){
                    if(s[i]==v[k]) break;
                }
                if(k==m){
                    dp[i][j]=1;
                    continue;
                }
                if(dp[i+1][j] < 1+dp[i+1][k+1]){
                    dp[i][j]=dp[i+1][j];
                }else{
                    dp[i][j]=1+dp[i+1][k+1];
                }
    
            }
        }
        if(dp[0][0]>=501){
            return -1;
        }
        return dp[0][0];
}
int main(){
    string s,v;
    cin>>s>>v;
    cout<<shortestSubsequence(s,v)<<endl;
}