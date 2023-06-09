#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int data;
    cout<<"Enter Data "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);

    root->left = takeInput();
    root->right = takeInput();

    return root;

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
    BinaryTreeNode<int>* root = takeInput();
    printTree(root);
    delete root;
    return 0;
}