#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int max=a[0]*n;
    for(int i=1;i<n;i++){
        int mul=a[i]*(n-i);
        if(mul>max) max=mul;
    }
    cout<<max<<endl;

}