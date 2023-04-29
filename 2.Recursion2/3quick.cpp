#include<iostream>
using namespace std;
void swap(int a[],int i,int j){
    int t =a[j];
    a[j]=a[i];
    a[i]=t;
}
int partition(int a[],int sp,int ep){
    int x=a[sp];
    int count=0;
    for(int i=sp;i<=ep;i++){
        if(a[i]<x){
            count++;
        }
    }
    int c=count+sp;
    swap( a,sp,c);
    int i=sp,j=ep;
    while(i<j){
        if(a[i]<x){
            i++;
        }
        else if(a[j]>=x){
            j--;
        }
        else{
            swap(a,i,j);
            i++;
            j--;
        }

    }
    return c;
    
}
void quicksort(int a[],int sp,int ep){
    if(ep<=sp){
        return;
    }
    int c=partition(a,sp,ep);
    quicksort(a,sp,c-1);
    quicksort(a,c+1,ep);
}
int main(){
    int n;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter elelments"<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}