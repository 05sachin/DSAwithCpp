#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
void Delete(int pos,Node* &head){
    if(head->next==NULL) return;
    if(pos==0){
        head=head->next;
        return ;
    }
    if(pos==1){
        Node *p=head->next;
        head->next=p->next;
        return;
    }
    Delete(pos-1,head->next);
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
    Delete(pos,head);
    print(head);

}
