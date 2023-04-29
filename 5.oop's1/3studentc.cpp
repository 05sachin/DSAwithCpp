#include<bits/stdc++.h>
using namespace std;
class Student{
    //default private specifier applied
    
    int age;
    public:
        char * name;
        Student(int age,char* name){
            this->age=age;
            // shallow copy
            // this->name=name; name variable stored char array address
            // deep copy
            this->name= new char[strlen(name)+1];
            strcpy(this->name,name); 
        } 
        //copy constructor
        Student( Student const &s){
            this->age=s.age;
            // shallow copy
            // this->name=s.name;
            // deep copy 
            this->name = new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
        }
        void display(){
            cout<<name<<" "<<age<<endl;
        }
};