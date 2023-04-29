
// For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

void print(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data<<" ";
        
        if(node->left!=NULL) {
            
            q.push(node->left);
        }
        if(node->right!=NULL){
            
            q.push(node->right);
        }
        }
        cout<<endl;
    }
}
void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data<<": ";
        
        if(node->left!=NULL) {
            cout<<"L"<<node->left->data<<",";
            q.push(node->left);
        }
        if(node->right!=NULL){
            cout<<"R"<<node->right->data;
            q.push(node->right);
        }
        cout<<endl;
    }
}
BinaryTreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter root data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();

        int leftData;
        cout<<"Enter left child of "<<node->data<<endl;
        cin>>leftData;
        if(leftData!=-1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            node->left = leftChild;
            q.push(leftChild);
        }
        int rightData;
        cout<<"Enter right child of "<<node->data<<endl;
        cin>>rightData;

        if(rightData!=-1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
            node->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"-----------------"<<endl;
    print(root);

    
}