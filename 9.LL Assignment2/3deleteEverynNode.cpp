#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
Node* deleteN(Node* head,int m,int n){
    if(head==NULL){
        return head;
    }
    Node* temp=NULL;
    Node* tail=NULL;
    int i=m;
    while(i!=0 && head!=NULL){
        if(temp==NULL){
            temp=head;
            tail=head;
        }else{
            tail->next=head;
            tail=tail->next;
        }
        head=head->next;
        i--;
    }
    i=n;
    Node* del=temp;
    while( i !=0 && head!=NULL){
        head=head->next;
        i--;
    }
    
    tail->next=deleteN( head ,m,n);
    return temp;  

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
    print(deleteN(head,m,n));
    
}