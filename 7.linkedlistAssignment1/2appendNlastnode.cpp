#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
int sizef( Node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;

}
Node* append(int n,Node* head){
    int m = sizef(head);
    if(n==0||head==NULL||n==m) return head;
    Node *temp=head;
    for(int i=0;i<m-n-1;i++){
        temp=temp->next;
    }
    Node *head2=temp->next;
    temp->next=NULL;
    Node *tail=head2;
    while(tail->next!=NULL&& tail != NULL){
        tail=tail->next;
    }
    tail->next=head;
    
    return head2;

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
    int last;
    cin>>last;
    Node *head2=append(last,head);
    print(head2);

}