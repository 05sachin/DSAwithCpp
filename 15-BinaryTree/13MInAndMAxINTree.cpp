// For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
// Return the output as an object of Pair class, which is already created.
#include<iostream>
#include<queue>
#include<climits>
#include "BinaryTreeNode.h"
using namespace std;

pair<int,int> minAndMax(BinaryTreeNode<int>* root){
    if(root==NULL) return {INT_MAX,INT_MIN};

    pair<int,int> p1 = minAndMax(root->left);
    pair<int,int> p2 = minAndMax(root->right);

    int minVal = min(root->data,min(p1.first,p2.first));
    int maxVal = max (root->data,max(p1.second,p2.second));

    return {minVal,maxVal};
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
  
    BinaryTreeNode<int>* root = takeInputLevelWise();
    
    printLevelWise(root);
    cout<<"MINIMUM: "<<minAndMax(root).first<<endl;
    cout<<"MAXIMUM: "<<minAndMax(root).second<<endl;
    delete root;
    return 0;
}