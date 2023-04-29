#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
class Pair{
public:
    Node* head;
    Node* tail;
};
Pair reverse_1(Node* head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallans = reverse_1(head->next);
    
    smallans.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;

}
Node* reverse(Node* head){
   return reverse_1(head).head;
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
    print(reverse(head));
    

}