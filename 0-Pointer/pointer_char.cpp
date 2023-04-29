#include<iostream>
using namespace std;
int main(){
    char c[]="sachin";
    cout<<&c<<endl;
    char* p=&c[0];
    cout<<p<<endl;
    char c1='a';
    cout<<c1<<endl;
    char * t=&c1;
    c1++;
    cout<<t<<endl;

}