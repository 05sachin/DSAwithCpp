// Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

pair<bool,int> balanced(BinaryTreeNode<int>* root){
    if(root==NULL) return {true,-1};
    
    pair<bool,int> p1 = balanced(root->left);
    pair<bool,int> p2 = balanced(root->right);
    bool ans =p1.first&&p2.first&& (abs(p1.second-p2.second)<=1)?true:false;
    
    int d =1+ max(p1.second,p2.second);
    

    return {ans,d};

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

    cout<<"Balanced : "<<balanced(root).first<<endl;

}