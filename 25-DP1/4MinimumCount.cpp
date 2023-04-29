/*Problem Description:
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.*/
#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

int minimumCount(int n){
    
    if(pow((sqrt(n)),2) ==n){
        return 1;
    }
    if(n<=3){
        return n;
    }
    int res=    INT_MAX;
    for(int i=1;i*i<=n;i++){
        int t = n - i*i;
        res=min(res,1+minimumCount(t));
    }
    return res;

}

int minimumCount_1Info(int n,int* arr){
    
    if(sqrt (n) -floor(sqrt(n))==0){
        return arr[n]=1;
    }
    if(n<=3){
        return arr[n]=n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int res=    INT_MAX;
    for(int i=1;i*i<=n;i++){
        int t = n - i*i;
        res=min(res,1+minimumCount(t));
    }
    return arr[n]=res;

}
int minimumCount_1(int n){
    
    int* arr = new int[n+1];
   
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
     arr[0]=0;
    return minimumCount_1Info(n,arr);

}

int minimumCount_2(int n){
    if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    int* arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    for(int j=4;j<=n;j++){
        int res= INT_MAX;
        for(int i=1;i*i<=j;i++){
            int t = j - i*i;
            res=min(res,1+arr[t]);
        }
        arr[j]=res;
    }
    return arr[n];

}
int main(){
    int n;
    cin>>n;
    // cout<<minimumCount(n)<<endl;
    cout<<minimumCount_1(n)<<endl;
    // cout<<minimumCount_2(n)<<endl;
}