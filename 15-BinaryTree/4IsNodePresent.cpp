#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;
bool isPresent(BinaryTreeNode<int>* root,int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    
    return isPresent(root->left,x)||isPresent(root->right,x) ;

}
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
        }
        if(node->right!=NULL){
            cout<<"R "<<node->right->data;
            q.push(node->right);
            
        }
        cout<<endl;
    }
}

int  main() {
    int x;
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cin>>x;
    printLevelWise(root);
    cout<<"no. of nodes "<<isPresent(root,x)<<endl;
    delete root;
    return 0;
}