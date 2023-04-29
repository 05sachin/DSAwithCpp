/*Problem Description:
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.*/
#include<iostream>
using namespace std;

int stairCase(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int sum=0;
    sum = sum + stairCase(n-1) + stairCase(n-2) + stairCase(n-3);
    return sum;
}
int stairCase_1Info(int n,int* arr){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int sum=0;
    sum = sum + stairCase_1Info(n-1,arr) + stairCase_1Info(n-2,arr) + stairCase_1Info(n-3,arr);
    return arr[n]=sum;
}
int stairCase_1(int n){
    int* arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    return stairCase_1Info(n,arr);
}

int stairCase_2(int n){
    int* arr = new int[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
       
        arr[i]=arr[i-1] + arr[i-2]+arr[i-3];
    }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<stairCase(n)<<endl;
    cout<<stairCase_1(n)<<endl;
    cout<<stairCase_2(n)<<endl;

}