#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
void insert(int pos,int data,Node* &head){
    if(head==NULL) return;
    if(pos==0){
        Node *node=new Node(data);
        node->next=head;
        head=node;
        return ;
    }
    if(pos==1){
        Node *node=new Node(data);
        node->next=head->next;
        head->next=node;
        return;
    }
    insert(pos-1,data,head->next);
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
    int pos;
    cin>>pos;
    int data;
    cin>>data;
    insert(pos,data,head);
    print(head);

}
