#include<bits/stdc++.h>
using namespace std;
#include "9polynomialc.cpp"
int main(){
    int s1,s2;
    cin>>s1;

    int* degA1=new int[s1];
    int* coeffA1=new int[s1];
    for(int i=0;i<s1;i++){
        cin>>degA1[i];
    }
    for(int i=0;i<s1;i++){
        cin>>coeffA1[i];
    }

    Polynomial p1;
     
    for(int i=0;i<s1;i++){
        p1.setcoeff(degA1[i],coeffA1[i]);
    }

    cin>>s2;

    int* degA2=new int[s2];
    int* coeffA2=new int[s2];
    for(int i=0;i<s2;i++){
        cin>>degA2[i];
    }
    for(int i=0;i<s2;i++){
        cin>>coeffA2[i];
    }

    Polynomial p2;
     
    for(int i=0;i<s2;i++){
        p2.setcoeff(degA2[i],coeffA2[i]);
    }
    p1.print();
    p2.print();
    label:
    char choice;
    cin>>choice;
switch(choice){
    // add
    case '+':
    {
    Polynomial p3= p1+p2;
    p3.print();
    break;
    }
    // subtract
    case '-':
    {
        Polynomial p3=p1-p2;
        p3.print();
        break;
    }
    // multiply
    case '*':
    {  
        Polynomial p3=p1*p2;
        p3.print();
        break;

    }
    //copy constructor
    case 'c':
    {
        Polynomial p3(p1);
        p3.print();
        break;
    }
    // copy assignment operator
    case '=':
    {
        Polynomial p3;
        p3=p1;
        p3.print();
        break;
    }
    default:
    {
      return 0;
    }
}
goto label;
}