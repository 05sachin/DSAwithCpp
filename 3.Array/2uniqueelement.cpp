#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int unique(int a[],int n){
    int XOR=0;
    for(  int i=0;i<n;i++){
        XOR=XOR^a[i];
    }
    return  XOR;
}
int main(){
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int XOR =unique(a,n);
    cout<< XOR <<endl;
}