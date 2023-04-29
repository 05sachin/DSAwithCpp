#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter RootData "<<endl;
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
        cout<<"Enter left Child of "<<node->data<<endl;
        int ldata;
        cin>>ldata;
        if(ldata!=-1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(ldata);
            node->left = leftChild;
            q.push(leftChild);
        }
        int rdata;
        cout<<"Enter Right Child of "<<node->data<<endl;
        cin>>rdata;
        if(rdata!=-1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rdata);
            node->right = rightChild;
            q.push(rightChild);
        }

    }
    
    return root;

}
void printLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data<<": ";
        if(node->left!=NULL) {
            cout<<"L "<<node->left->data<<",";
            q.push(node->left);
        }else{
            cout<<"L "<<-1<<",";
        }
        if(node->right!=NULL){
            cout<<"R "<<node->right->data;
            q.push(node->right);
            
        }else{
            cout<<"R "<<-1;
        }
        cout<<endl;
    }
}
void printTree(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    cout<<root->data<<": ";
    if(root->left!=NULL) cout<<" L "<<root->left->data<<",";
    if(root->right!=NULL) cout<<" R "<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int  main() {
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2= new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}