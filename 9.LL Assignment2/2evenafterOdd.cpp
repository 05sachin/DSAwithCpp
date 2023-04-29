#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
Node* evenAfterOdd(Node* head){
    Node* oh=NULL;
    Node* ot=NULL;
    Node* eh=NULL;
    Node* et=NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(eh==NULL){
                eh=head;
                et=head;
            } 
            else{
                et->next=head;
                et=et->next;
            }
        }else{
            if(oh==NULL){
                oh=head;
                ot=head;
            }else{
                ot->next=head;
                ot=ot->next;
            }
        }
        head=head->next;
    }
    if(et!=NULL){
        et->next=NULL;
    }
    if(oh==NULL){
        oh=eh;
    }else{
        ot->next=eh;
    }
    return oh;

}
Node* input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    Node* head=input();
    head=evenAfterOdd(head);
    print(head);
    
}