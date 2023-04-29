#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sumset(int n,int ip[],int op[],int k,int pos=0){
    if(n==0){
        if(k==0){
            for(int i=0;i<pos;i++){
                cout<<op[i]<<" ";
            }
            cout<<endl;
        }
        return ;
        
    }
    sumset(n-1,ip+1,op,k,pos);
    op[pos]=ip[0];
    sumset(n-1,ip+1,op, k-ip[0],pos+1);
    
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int  k;
    cin>>k;
    int op[n];
    sumset(n,a,op,k);
}