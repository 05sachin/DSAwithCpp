#include<bits/stdc++.h>
using namespace std;
#include "5stackUsingLinkedListclass.cpp"

int main(){
    Stack<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;
}