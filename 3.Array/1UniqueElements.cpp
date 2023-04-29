#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int unique(int a[],int n){
   
    for(  int i=0;i<n-1;i+=2){
        if(a[i]!=a[i+1]){
            return i;
        }
    }
    return n-1;
}
int main(){
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int i=unique(a,n);
    cout<<a[i]<<endl;
}