#include<iostream>
using namespace std;
int Knapsack(int n,int* w,int* v,int W){

    if(n==0 || W==0){
        return 0;
    }
    int a=0;
    if(w[0]<=W){
        a=v[0]+Knapsack(n-1,w+1,v+1,W-w[0]);
    }
    int b=Knapsack(n-1,w+1,v+1,W);
    return max(a,b);

}
int KnapsackMemo(int n,int* w,int* v,int W,int** dp){

    if(n==0 || W==0){
        return dp[n][W]=0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int a=0;
    if(w[0]<=W){
        a=v[0]+KnapsackMemo(n-1,w+1,v+1,W-w[0],dp);
    }
    int b=KnapsackMemo(n-1,w+1,v+1,W,dp);
    return dp[n][W]=max(a,b);

}
int knapsack_1(int n,int* w,int* v,int W){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[W+1];
        for(int j=0;j<=W;j++){
            dp[i][j]=-1;
        }
    }

    return KnapsackMemo(n,w,v,W,dp);
}

int knapsackDp(int n,int* w,int* v,int W){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            int a=0;
            if(w[i-1]<=j){
                a=v[i-1]+dp[i-1][j-w[i-1]];
            }
            int b=dp[i-1][j];
            dp[i][j]=max(a,b);
            
        }
        
          
    }
    return dp[n][W];
}
int knapsackDp1(int n,int* w,int* v,int maxW){
    
    int* pre=new int[maxW+1];
    int* curr=new int[maxW+1];
    for(int i=0;i<=maxW;i++){
        pre[i]=0;
        curr[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxW;j++){
            int a=0;
            if(w[i-1]>j){
                curr[j]=pre[j];
            }else{
                a=v[i-1]+pre[j-w[i-1]];
                int b=pre[j];
                curr[j]=max(a,b);
            }
         
        }
        
        for(int k=0;k<=maxW;k++){
           pre[k]=curr[k];
        }
    }
    return curr[maxW];
}
int main(){
    int n;
    cin>>n;
    int w[n];
    int v[n];

    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int W ;
    cin>>W;
    // cout<<knapsack_1(n,w,v,W)<<endl;
    cout<<knapsackDp(n,w,v,W)<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<knapsackDp1(n,w,v,W)<<endl;

    // cout<<Knapsack(n,w,v,W)<<endl;
}