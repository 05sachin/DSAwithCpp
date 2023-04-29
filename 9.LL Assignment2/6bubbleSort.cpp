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
Node* bubble(Node* head){
    int n=size(head);
    for(int i=0;i<n-1;i++){
        Node* pre=NULL;
        Node* curr=head;
        for(int j=0;j<n-i-1;j++){
            Node* next=curr->next;
            if(curr->data>curr->next->data&&pre==NULL){
                curr->next=next->next;
                next->next=curr;
                head=next;
                pre=next;
            }else if(curr->data>curr->next->data){

                pre->next=curr->next;
                curr->next=next->next;
                next->next=curr;
                pre=next;

            }else{
                pre=curr;
                curr=next;
            }
        }
       
    }
     return head;
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
    
    print(bubble(head));
}