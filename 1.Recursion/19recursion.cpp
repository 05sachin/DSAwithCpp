#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int index(int a[],int s,int x,int op[]){
    if(s==0){
        return 0;
    }
    int ans=index(a+1,s-1,x,op);
    for(int i=0; i <ans;i++){
        op[i]=op[i]+1;
    }
    if(a[0]==x){
        for(int i=ans-1; i >=0;i--){
           op[i+1]=op[i];
        }
        op[0]=0;
        return ans+1;
    }
    return ans;
}
int main(){
    int s;
    cout<<"enter size"<<endl;
    cin>>s;
    cout<<"enter elements"<<endl;
    int* a= new int[s];
    int* op=new int [s];
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    cout<<"search element"<<endl;
    int x;
    cin>>x;
    int ans=index(a,s,x, op);
    cout<<ans<<endl;
    for(int i=0;i< ans;i++){
       cout<<op[i]<<",";
    }
} 