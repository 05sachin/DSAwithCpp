#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
int size(Node* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
Node* kreverse(Node* head,int n){
    int m=size(head);
    if(m<n){
        return head;
    }
    Node* pre=NULL;
    Node* curr=head;
    for(int i=0;i<n && curr!= NULL;i++){
        Node* nex=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nex;
    }
    
    head->next=kreverse(curr,n);
    return pre;

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
    int n;
    cin>>n;
    print(kreverse(head,n));
    
}