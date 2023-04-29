#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sumset(int n,int ip[],int op[][20],int k){
    if(n==0){
        if(k==0){
            op[0][0]={0};
            return 1;
        }else{
            return 0;
        }
        
    }
    int count=sumset(n-1,ip+1,op,k);
    int count1=sumset(n-1,ip+1,op+count, k-ip[0]);
    for(int i=0;i<count1;i++){
        op[count+i][0]++;
        for(int j=op[count+i][0];j>1;j--){
            
            op[count+i][j]=op[count+i][j-1]; 
        }
        op[count+i][1]=ip[0];
    }
    return count+count1;
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
    int m=pow( 2,n);
    int op[ m][20];
    int count=sumset(n,a,op,k);
    for(int i=0;i<count;i++){
        for(int j=1;j<=op[i][0];j++){
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }


}