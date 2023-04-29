#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
        int age;
        int const rollno;
        int &x;   // age reference variable
        Student(int r,int age):rollno(r),age(age),x(this->age){
            
        }
};