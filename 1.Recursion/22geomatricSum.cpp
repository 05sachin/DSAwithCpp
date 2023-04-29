#include<iostream>
#include<bits/stdc++.h>
using namespace std;
double gsum(int n){
    if(n==0){
        return 1;
    }
    double ans=1/pow(2,n)+gsum(n-1);//1+1/2+1/2^2...
    return ans;
    
}
int main(){
    int n;
    cin>>n;
    cout<<gsum(n)<<endl;
}