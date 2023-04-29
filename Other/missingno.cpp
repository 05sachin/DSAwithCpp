#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int missing(int n,int a[]){
    int res=0;
    for(int i=0;i<n;i++){
         res=res^(i+1)^a[i];
    }
    res=res^(n+1);  // 1,4,3 missing no 2
    return res;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<missing(n,a)<<endl;
}
