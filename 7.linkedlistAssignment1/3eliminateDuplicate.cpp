#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
Node* duplicate(Node *head){
    if(head->next==NULL||head->next==NULL){
        return head;
    }
    Node *p=head->next;
    if(head->data==p->data) {
        head->next=p->next;
        duplicate(head);
    }else{
        duplicate(head->next);
    }
    return head;
}
Node* input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *node=new Node(data);
        if(head==NULL){
            head=node;
            tail=node;
        }else{
            tail->next=node;
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
    Node *head=input();
    Node *head2=duplicate(head);
    print(head2);
}