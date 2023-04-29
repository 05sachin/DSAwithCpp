#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
int find(int val,Node* head,int pos=0){
    if(head==NULL) return -1;
    if(head->data==val){
        return pos;
    }
    return find(val,head->next,pos+1);
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
    int data;
    cin>>data;
    cout<<find(data,head)<<endl;
    print(head);

}