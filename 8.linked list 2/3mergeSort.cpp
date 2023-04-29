#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
int size(Node *head){
    int count =0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
Node* mid(Node *head){
    Node *slow= head;
    Node *fast= head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge(Node* head1,Node* head2){
    Node *fhead=NULL;
    Node *ftail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(fhead==NULL){
            if(head1->data < head2->data){
                fhead = head1;
                ftail = head1;
                head1=head1->next;
            }else if(head2->data < head1->data){
                fhead= head2;
                ftail  = head2;
                head2=head2->next;
            }else{
                fhead = head1;
                ftail = head1;
                head1=head1->next;

                ftail->next=head2;
                ftail=ftail->next;
                head2=head2->next;

            }
        }else{
            if(head1->data < head2->data){
                ftail->next = head1;
                ftail=ftail->next;
                head1=head1->next;
            }else if(head2->data < head1->data){
                ftail->next  = head2;
                ftail=ftail->next;
                head2=head2->next;
            }else{
                
                ftail->next = head1;
                head1=head1->next;
                ftail=ftail->next;

                ftail->next=head2;
                ftail=ftail->next;
                head2=head2->next;

            }
        }
    }
    if(head1!=NULL){
        if(fhead==NULL){
            fhead=head1;
        }else{
            ftail->next=head1;
        }
    }else{
        if(fhead==NULL){
            fhead=head2;
        }else{
            ftail->next=head2;
        }
    }

    return fhead;
    
}
Node* mergeSort(Node *head){
    if(head->next==NULL){
        return head ;
    }
    Node* m = mid(head);
    Node* p=m->next;
    m->next=NULL;
    head=mergeSort(head);
    p=mergeSort(p);
    head=merge(head,p);
    return head;
    

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
    head=mergeSort(head);
    print(head);
    

}