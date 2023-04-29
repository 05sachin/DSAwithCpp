#include<bits/stdc++.h>
using namespace std;
class Student{
    static int totalofStudent;
    public:
        int roll;
        int age;
        Student(){
            totalofStudent++;
        }
        static int gettotalofStudent(){
            return totalofStudent;
        }
};
int Student::totalofStudent=0;//initialze static data member