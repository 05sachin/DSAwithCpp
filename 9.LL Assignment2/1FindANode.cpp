#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
int find(Node* head,int x,int count=0){
    if(head==NULL){
        return -1;
    }
    if(x==head->data){
        return count;
    }
    
    return find(head->next,x,count+1);
    
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
    print(head);
    int x;
    cin>>x;
    cout<<find(head,x)<<endl;
}