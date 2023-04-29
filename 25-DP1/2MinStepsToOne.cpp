/*Problem Description:
Given a positive integer 'n',  find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

Write brute-force recursive solution for this*/
#include<iostream>
#include<climits>
using namespace std;

int minStepsToOne_1(int n){
    if(n<=1){
        return 0;
    }
    int res = INT_MAX;
    res = min(res,minStepsToOne_1(n-1));
    if(n%2==0){
        res=min(res,minStepsToOne_1(n/2));
    }
    if(n%3==0){
        res = min(res,minStepsToOne_1(n/3));
    }

    return res+1;


}
int minStepsToOne_2Info(int n,int* arr){
    if(n<=1){
        return arr[n]=0;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int res = INT_MAX;
    res = min(res,minStepsToOne_1(n-1));
    if(n%2==0){
        res=min(res,minStepsToOne_1(n/2));
    }
    if(n%3==0){
        res = min(res,minStepsToOne_1(n/3));
    }
    return arr[n]=res+1;
}
int minStepsToOne_2(int n){ // top to down
    int* arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    return minStepsToOne_2Info(n,arr);
}

int minStepsToOne_3(int n){// bottom to up
    int* arr = new int[n+1];
    arr[1]=0;

    for(int i=2;i<=n;i++){
        int res = INT_MAX;
        res = min(res,arr[i-1]);
        if(i%2==0){
            res=min(res,arr[i/2]);
        }
        if(i%3==0){
            res = min(res,arr[i/3]);
        }
        arr[i]=res+1;
    }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<minStepsToOne_1(n)<<endl;
    cout<<minStepsToOne_2(n)<<endl;
    cout<<minStepsToOne_3(n)<<endl;
}