/*Chapter Assignment
Problem Statement: Matrix Chain Multiplication
Problem Level: HARD
Problem Description:
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[]

Output Format :
Line 1 : Minimum number of multiplication needed

Constraints :
1 <= n <= 100

Sample Input 1 :
3
10 15 20 25

Sample Output :
8000

Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order   A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order   (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000
*/

#include<iostream>
#include<climits>
using namespace std;
int matrixChainMultiplication(int* arr,int pre,int next){
    if(pre+1==next || pre==next){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=pre+1;k<next;k++){
        ans = min(ans,matrixChainMultiplication(arr,pre,k)+matrixChainMultiplication(arr,k,next)+arr[pre]*arr[k]*arr[next]);
    }
    return ans;

    
}
int matrixChainMultiplicationMemo(int* arr,int pre,int next,int** dp){
    if(pre+1==next || pre==next){
        return dp[pre][next]=0;
    }
    if(dp[pre][next]!=-1){
        return dp[pre][next];
    }
    int ans=INT_MAX;
    for(int k=pre+1;k<next;k++){
        ans = min(ans,matrixChainMultiplicationMemo(arr,pre,k,dp)+matrixChainMultiplicationMemo(arr,k,next,dp)+arr[pre]*arr[k]*arr[next]);
    }
    return dp[pre][next]=ans;

    
}
int matrixChainMultiplicationMemo_1(int* arr,int n){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    return matrixChainMultiplicationMemo(arr,0,n,dp);
}
long long matrixChainMultiplicationTab(int* arr,int n){
    long long ** dp = new long long *[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new long long [n+1];
        
    }
    for(int pre = n;pre>=0;pre--){

        for(int next=0;next<=n;next++){
            if(pre+1==next || pre==next){
                dp[pre][next]=0;
                continue;
            }
            long long ans=INT_MAX;
            for(int k=pre+1;k<next;k++){
                ans = min(ans,dp[pre][k]+dp[k][next]+arr[pre]*arr[k]*arr[next]);
            }
            dp[pre][next]=ans;
        }
    }
    return dp[0][n];
   

    
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    
   cout<<matrixChainMultiplicationMemo_1(arr,n)<<endl;
   cout<<matrixChainMultiplicationTab(arr,n)<<endl;
    cout<<matrixChainMultiplication(arr,0,n)<<endl;
}