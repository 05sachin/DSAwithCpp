#include<iostream>
using namespace std;
int firstindex(int a[],int size){
    if(size==0){
        return 0;
    }
    int ans=firstindex(a+1,size-1);
    return a[0]+ ans;
}
int main(){
    int size;
    cout<<"enter size"<<endl;
    cin>>size;
    cout<<"enter elements"<<endl;
    int* a=new int[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<firstindex(a,size)<<endl;
}