#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
Node* input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *n=new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=tail->next;

        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int leng(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1+leng(head->next);
}
int main(){
    Node *head=input();
    print(head);
    cout<<leng(head)<<endl;
}