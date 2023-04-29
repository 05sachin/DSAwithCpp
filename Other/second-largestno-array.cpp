#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largest(int a[],int n){
    int res=-1,lar=0,i;
    for(i=1;i<n;i++){
        if(a[i]>a[lar]){
            res=lar;
            lar=i;
        }else if(a[i]!=a[lar]){
            if(res=-1 || a[i]>a[res]){
                res=i;
            }
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<a[largest(a,n)]<<endl;
    return 0;
}