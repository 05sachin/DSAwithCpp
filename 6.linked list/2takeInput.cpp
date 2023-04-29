#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
int element(Node *head,int pos){
    int i=0;
    while(i<pos){
        head=head->next;
        i++;
    }
    return head->data;
}
int length(Node *head){
    int count=0;
    while(head!=NULL){
        count+=1;
        head=head->next;
    }
    return count;
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
    cout<<length(head)<<endl;
    int pos;
    cin>>pos;
    cout<<element(head,pos)<<endl;
}