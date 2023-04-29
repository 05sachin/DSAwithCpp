#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template < typename T >

class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this->data=data;
        next=NULL;
    }
};

template < typename T>
class Stack{
    Node<T> *head;
    int s; //no of elements in stack
    public:
    Stack(){
        head=NULL;
        s=0;
    }
    // size function
    int size(){
        return s;
    }
     
    bool isEmpty(){
        return head==NULL;
    }

    void push(T data){
        Node<T> *node=new Node<T>(data);
        node->next=head;
        head=node;
        s++;
    }

    T top(){
        if(head==NULL) {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }

    T pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        T d=head->data;
        Node<T> *temp=head;
        head=head->next;
        delete temp;
        s--;
        return d;
    }

};
