#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
Node* reverse(Node* head){
    Node* pre =NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
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
    print(reverse(head));
    

}