#include<iostream>
using namespace std;
template<typename T>
class Node{
    T a;
    public:
    Node(T a){
        this->a=a;
    }
    void show(){
        cout<<this->a<<endl;
    }
    
};
int main(){
    Node<int>* n =new Node<int>(5);
    (*n).show();
}
