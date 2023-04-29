#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    int n;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+m);
    sort(b,b+n);
    int i=0,j=0;
    while(i<m& j<n){
        if(a[i]<b[j]){
            i++;
        }else if(a[i]==b[j]){
            cout<<a[i]<<" ";
            i++;
            j++;
        }else{
            j++;
        }
    }
}