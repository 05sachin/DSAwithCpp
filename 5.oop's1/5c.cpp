#include<bits/stdc++.h>
using namespace std;
#include "5static.cpp"
int main(){
    Student s1,s2,s3,s4;
    // cout<<Student::totalofStudent<<endl;
    cout<<Student::gettotalofStudent()<<endl;//:: scope resolution operator
    Student s5;
    cout<<s1.gettotalofStudent()<<endl;
}