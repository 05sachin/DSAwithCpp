#include<iostream>
using namespace std;
void rotateArray(int n,int a[],int x){
    if(x==0){
        return;
    }
    int temp=a[0];
    for(int i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    a[n-1]=temp;
    rotateArray(n,a,x-1);
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
    rotateArray(n,a,x);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}