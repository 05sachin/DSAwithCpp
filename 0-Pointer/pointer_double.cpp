#include<iostream>
using namespace std;
void increment1(int** p){
    p=p+1; 
}
void increment(int** p){
     *p=*p+1;
}
void increment(int** p){
    **p=**p+1;
}
int main(){
    int i=10;
    int *p=&i;
    int* * p2=&p;
    cout<<p2<<endl;
    cout<<&p<<endl;

    cout<<p<<endl;
    cout<<&i<<endl;
    cout<<*p2<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;
}