#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int tem =power(x,n/2);
    int res=tem*tem;
    if(n%2==0){
        return res;           //logn
    }
    else{
        return res*x;
    }
}
int main(){
    int x;
    int n;
    cout<<"enter values";
    cin>>x;
    cin>>n;
    cout<<power(x,n)<<endl;

}