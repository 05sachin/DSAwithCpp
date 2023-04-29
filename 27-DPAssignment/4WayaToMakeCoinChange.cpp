/*Chapter Assignment
Problem Statement: Ways To Make Coin Change
Problem Level: MEDIUM
Problem Description:
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.

Output Format
Print the total total number of ways i.e. W.

Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec

Sample Input 1 :
3
1 2 3
4

Sample Output 1 :
4

Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250

Sample Output 2 :
13868903
*/

#include<iostream>
using namespace std;
int waysToMakeChoinChange(int* d,int n,int v,int i){
    if(v<0){
        return 0;
    }
    if(v==0){
        return 1;
    }
    int ans=0;
    for(int j=i;j<n;j++){
        ans+=waysToMakeChoinChange(d,n,v-d[j],j);
    }
    return ans;

}
int waysToMakeChoinChangeMemo(int* d,int n,int v,int i,int** dp){
    if(v<0){
        return 0;
    }
    if(v==0){
        return dp[0][i]=1;
    }
    if(dp[v][i]!=-1){
        return dp[v][i];
    }
    int ans=0;
    for(int j=i;j<n;j++){
        ans+=waysToMakeChoinChangeMemo(d,n,v-d[j],j,dp);
    }
    return dp[v][i]=ans;

}
int waysToMakeChoinChangeMemo_1(int* d,int n,int v){
    int** dp =new int*[v+1];
    for(int i=0;i<=v;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
        
    }
    return waysToMakeChoinChangeMemo(d,n,v,0,dp);
}
int waysToMakeChoinChangeMemoTab(int* d,int n,int v){
    int** dp =new int*[v+1];
    for(int i=0;i<=v;i++){
        dp[i] = new int[n+1];
        
        
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=v;i++){
        for(int k=n-1;k>=0;k--){
            int ans = 0;
            for (int j = k; j < n && i-d[j]>=0; j++)
            {
                ans += dp[i - d[j] ][j];
            }
            dp[i][k]=ans;
        }
    }
    return dp[v][0];
}
int main(){
    int n;
    cin>>n;

    int d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    int v;
    cin>>v;
    cout<<waysToMakeChoinChangeMemo_1(d,n,v)<<endl;
    cout<<waysToMakeChoinChangeMemoTab(d,n,v)<<endl;
    cout<<waysToMakeChoinChange(d,n,v,0)<<endl;
}