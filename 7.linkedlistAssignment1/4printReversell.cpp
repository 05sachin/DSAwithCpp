#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
int size(Node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
bool checkpalindrome(Node *head){
    int n=size(head);
    if(n==1){
        return true;
    }
    int mid=n/2;
    Node *tail=head;
    while(mid>1){
        tail=tail->next;
        mid--;
    }
    Node *head2=tail->next; // divide ll in two parts
    tail->next=NULL;
    Node *tail2=head2; 


    tail2=tail2->next;//reverse second list
    head2->next=NULL;
    while(tail2!=NULL){
        Node *temp=tail2;
        tail2=tail2->next;
        temp->next=head2;
        head2=temp;
    }
    while(head!=NULL && head2!=NULL){
        if(head->data != head2->data)  return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
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
    cout<<checkpalindrome(head)<<endl;

}