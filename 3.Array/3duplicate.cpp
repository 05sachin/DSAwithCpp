/*You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int unique(int a[],int n){
    int sum=0;
    for(  int i=0;i<n;i++){
        sum+=a[i];
    }
    int num=sum-((n-2)*(n-1))/2;//formula of sum of n-2 natural numbers
    return num;
}
int main(){
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num=unique(a,n);
    cout<<num<<endl;
}