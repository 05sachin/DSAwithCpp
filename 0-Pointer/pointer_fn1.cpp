#include<iostream>
using namespace std;
void print(int* p){
    cout<<*p<<endl;
}
void incrementPointer(int * p){
    p=p+1; // address do not change 
}
void increment(int * p){
    (*p)++; // value changed
}
int main(){
    int n=10;
    int* p=&n;
    print(p);
    cout<<*p<<endl;
    increment(p);
    cout<<*p<<endl;
}