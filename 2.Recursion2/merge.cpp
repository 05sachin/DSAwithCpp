#include<iostream>
using namespace std;
void merge(int a[],int sp,int mid,int ep){
    int n1=mid-sp+1;
    int n2=ep-mid;
    int m1[n1];
    int m2[n2];
    for(int i=0;i<n1;i++){
       m1[i]= a[sp+i];
    }
    for(int i=0;i<n2;i++){
       m2[i]= a[n1+i];
    }
    int i=0,j=0,k ;
    k=sp;
    while(i<n1&&j<n2){
        if(m1[i]<=m2[j]){
            a[k]=m1[i];
            i++;
            k++;
        }else{
            a[k]=m2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k]=m1[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=m2[j];
        j++;
        k++;
    }
    
}
void mergeSort(int a[],int sp,int ep){
    if(ep<=sp){
        return;
    }
    int mid=(ep-sp)/2;
    mergeSort(a,sp,mid);
    mergeSort(a,mid+1,ep);
    merge(a,sp,mid,ep);
}
int main(){
    int n;
    cout<<"size of array"<<endl;
    cin>>n;
    int a[n];
    cout<<"elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}