#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
Node* swap(Node* head,int i,int j){
    Node* temp=head;
    int c1=0;
    while(c1<i-1){
        temp=temp->next;
        c1++;
    }
   
    int c2=0;
    Node* temp2=head;
    while(c2<j-1){
        temp2=temp2->next;
        c2++;
    }
    if(i==0&&j==0){
        return head;
    }
    else if(i==0){
        Node* q=temp2->next;
        Node* p=head->next;
        temp2->next=head;
        temp2=temp2->next;
        temp2->next=q->next;
        head=q;
        head->next=p;
    }else if(j==0){
        Node* q=temp->next;
        Node* p=head->next;
        temp->next=head;
        temp=temp->next;
        temp->next=q->next;
        head=q;
        head->next=p;
    }else{
    Node* p=temp->next;
    temp->next=temp2->next;
    temp=temp->next;
    temp2->next=p;
    Node* q=p->next;
    p->next=temp->next;
    temp->next=q;
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
    int m,n;
    cin>>m>>n;
    print(swap(head,m,n));
    
}