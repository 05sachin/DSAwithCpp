#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long power(int x,int n){
    long long res=1;
    while(n>0){
        if(n%2!=0){
            res=res*x;
        }
        x=x*x;
        n=n/2;
    }
    return res;
}
int main(){
    int x,n;
    cout<<"enter values";
    cin>>x;
    cin>>n;
    cout<<power(x,n)<<endl;
}