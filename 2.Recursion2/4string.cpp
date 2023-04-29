#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string* s1=new string;
    getline(cin,*s1);
    cout<<*s1<<endl;
    string s;
    getline(cin,s);
    cout<<s<<endl;
    string s2 = s + *s1;
    cout<<s2<<endl;
    cout<<s.size()<<s.length()<<endl;
    cout<<s.substr(3)<<endl;//s.substr(0,l)
    cout<<s.find("sac")<<endl;//return index
}