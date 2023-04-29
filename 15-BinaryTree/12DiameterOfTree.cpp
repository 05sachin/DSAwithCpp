#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
  
    return 1+max(height(root->left),height(root->right));
    
}
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);
    int ans = leftH + rightH;

    ans= max(ans,max(leftD,rightD));
    return ans;
     
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){// optimal way
    if(root ==NULL ) return {0,0};

    pair<int,int> p1= heightDiameter(root->left);
    pair<int,int> p2 = heightDiameter(root->right);

    int h =1+ max(p1.first,p2.first);
    int d = max(p1.first+p2.first,max(p1.second,p2.second));


    return {h,d};

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
    cout<<"Diameter "<<diameter(root)<<endl;
    cout<<"Diameter "<<heightDiameter(root).second<<endl;
    
    delete root;
    return 0;
}