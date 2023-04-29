#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){//O(n^2)
        Node *newNode=new Node(data);
        if(head==NULL){
           head=newNode; 
        }else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    // Node *temp=head;
    while(head!=NULL){  
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){

    Node *head=takeInput();
    print(head);
    // statically
   /* Node n1(1);
    Node* head=&n1;
    
    Node n2(2);
     
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    print(head);
    print(head);
    
*/



   /* n1.next=&n2;
    cout<<head->data<<endl;
    cout<<n1.data<<" "<<n2.data<<endl;

    // dynamically
    Node *n3=new Node(10);
    Node *head=n3;
    Node *n4=new Node(20);
    n3->next=n4;*/
}