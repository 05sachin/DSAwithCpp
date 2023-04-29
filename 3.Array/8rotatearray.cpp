#include<iostream>
using namespace std;
void reverse(int n,int a[]){
    int i=0;
    int j=n-1;
    while(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
void rotateArray(int n,int a[],int x){
    reverse(n,a);
    reverse(n-x,a);
    reverse(x,a+n-x);
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