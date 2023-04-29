#include<iostream>
using namespace std;
int main(){
    // while(true){
    //     int i=10; scope based memory allocation
    // }
    // while(true){
    //     int* p=new int; not scope base
    // }
    int* p=new int;
    delete p; // only heap memory delete ,p not delete
    
    int * p1=new int[100];
    delete [] p;
}