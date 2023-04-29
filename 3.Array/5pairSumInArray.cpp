#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void pairsum(int n,int a[],int sum){
    sort(a,a+n);//nlog(n)
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==sum){
                cout<<a[i]<<" "<<a[j]<<endl;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    pairsum(n,a,x);
}