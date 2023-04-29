#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
int subset(int n,int a[],int  op[][ 20]){
    if(n ==0){
        op[0][0] = 0;
        return 1;
    }
    int size=subset(n-1,a+1,op);
    for(int i=0;i<size;i++){
        op[i+size][0]=op[i][0]+1;
        op[i+size][1]=a[0];
        for(int j=2;j<=op[i+size][0];j++){
            op[i+size][j]=op[i][j-1];
        }        
    }
    return 2*size;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int size=pow( 2 ,n);
    int op[n][20];
    int count=subset(n,a,op);
    for (int i=0 ;i<count;i++){
        for(int j=1;j<=op[i][0];j++){
            cout<<op[i][j]<<" ";
        }
        cout<<endl;

    }
}