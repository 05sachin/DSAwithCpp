#include<iostream>
#include "2complexNumberc.cpp"
using namespace std;
int main(){
    int I1,R1,I2,R2;
    cin>>R1>>I1;
    cin>>R2>>I2;
    Complex c1(R1,I1);
    Complex c2(R2,I2);
    c1.print();
    c2.print();
    int choice;
    cin>>choice;
    if(choice==1){
        c1.plus(c2);
        c1.print();
    }else if(choice == 2){
        c1.mul(c2);
        c1.print();
    }else{
        c1.print();
    }

}