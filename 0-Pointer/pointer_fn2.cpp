#include<iostream>
using namespace std;
int sum(int* a,int size){
    cout<<sizeof(a)<<endl; //array will pass as a pointer
    int s=0;
    for(int i=0;i<size;i++){
        s+=a[i];
    }
    return s;
}
int main(){
   int a[10];
   cout<<sizeof(a)<<endl;// array size
   int s=sum(a+3,10);// pass part of array from(3to10)
   cout<<s<<endl;
}