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
    int Xor=0;
    for(int i=0;i<n;i++) {
        Xor=Xor^a[i];
        }
    
    int s=Xor&(~(Xor-1));//right most set bit
    int resa=0,resb=0;
    for(int i=0;i<n;i++){
        if(a[i]&s){
            resa=resa^a[i];
        }
        else{
            resb=resb^a[i];
        }
    }
    cout<<resa<<resb<<endl;
    return 0;
    
}