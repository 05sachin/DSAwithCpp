#include<iostream>
using namespace std;
int sum(int a,int b=0,int c=0){
    return a+b+c;
}
int main(){
    int a,b,c;
    a=10;
    b=20;
    cout<<sum(a,b)<<endl;
    c=48;
    cout<<sum(a,b,c)<<endl;
}