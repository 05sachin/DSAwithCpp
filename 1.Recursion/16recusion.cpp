#include<iostream>
using namespace std;
int firstindex(int a[],int size,int x){
    if(size==0){
        return -1;
    }
    if(a[0]==x){
        return 0;
    }
    int ans=firstindex(a+1,size-1,x);
    return (ans<0)? -1:(ans+1);
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
    cout<<"search element"<<endl;
    int x;
    cin>>x;
    cout<<firstindex(a,size,x)<<endl;
}