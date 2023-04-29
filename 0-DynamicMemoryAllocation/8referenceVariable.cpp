#include<iostream>
using namespace std;
void increment(int& i){// call by reference ,variable do not create new memory  ,share memory with passed argument
    i++;
}
// bad practice,return by reference of local variable
int& f(int n){ //b/c memory of local variable cleared after return
    int a=n;
    return a;
}
int* f2() {
    int i=10;
    return &i;
}

int main(){
    int* p=f2();

    int i;
    i=10;

    int& k1= f(i);

    increment(i);
    int& j=i;// reference changes will reflect
    i++;
    cout<<j<<endl;
    cout<<i<<endl;
    int k=100;
    j=k;
    cout<<k<<endl;
}