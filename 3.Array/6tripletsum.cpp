#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int tripletsum(int n,int a[],int x){

    if(n<3){
        return 0;
    }
    int count=0;
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        if(i!=0 && a[i]==a[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=a[i]+a[j]+a[k];
            if(sum>x||(k<n-1&&a[k]==a[k+1])){
                k--;
            }else if(sum<x||(j>i+1 && a[j]==a[j-1])){
                j++;
            }else if(sum==x){
                count++;
                k--;
                j++;
            }
        }
        
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout<<tripletsum(n,a,x);
}