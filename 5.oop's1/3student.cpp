#include<bits/stdc++.h>
using namespace std;
#include "3studentc.cpp"
int main(){
    char name[]="abcd";
    Student s1(20,name);
    s1.display();

    Student s2(s1);
    s2.name[0]='x';
    // Student s2(24,name);
    s2.display();

    s1.display();
}