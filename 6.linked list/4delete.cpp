#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"

Node* Delete(Node *head,int i){
    int count=0;
    Node *temp=head;

    if(i==0){
        head=head->next;
        return head;
    }
    while(temp!=NULL&&count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a= temp->next;
        temp->next=a->next;
        delete a;
        
    }
    return head;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;
            // or tail=newnode
        }
        cin>>data;
    }
    return head;
}


void print(Node *head){
    // Node *temp=head;
    while(head!=NULL){  
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    Node *head=takeInput();
    print(head);
    int i;
    cin>>i;
    head=Delete(head,i);
    print(head);
}