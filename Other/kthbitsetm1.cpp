#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5,k=3;
    //method 1
    if(n&(1<<(k-1))!=0){
        cout<<"Yes";

    }
    else{
        cout<<"NO";
    }
    //method 2
    if((n>>(k-1))&1==1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}