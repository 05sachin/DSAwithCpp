// You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include "TreeNode.h"
using namespace std;
void replaceWithDepth(TreeNode<int>* root ,int k){
    if(root==NULL) return ;
    root->data = k;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],k+1);
    }

}
void replaceWithDepthRec(TreeNode<int>* root){
    if(root==NULL) return;
    queue<TreeNode<int>*> q;
    q.push(root);
    int k=0;
    while(!q.empty()){
        
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode<int>* node = q.front();
            q.pop();
            node->data=k;
            for(int j=0;j<node->children.size();j++){
                q.push(node->children[j]);
            }
        }
        k++;
    }
}
void printRepalceTree(TreeNode<int>* root){
    if(root==NULL) return;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode<int>* node = q.front();
            q.pop();
            cout<<node->data<<" ";
            for(int j=0;j<node->children.size();j++){
                q.push(node->children[j]);
            }
        }
        
        cout<<endl;
    }
}
void printTreeLevelWise(TreeNode<int>* root){
    
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data<<": ";
        for(int i=0;i<node->children.size();i++){
            cout<<node->children[i]->data<<",";
            q.push(node->children[i]);
        }
        cout<<endl;
    }
}
TreeNode<int>* inputLevelWise(){
    cout<<"Enter root data : "<<endl;
    int data;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        int n;

        cout<<"Enter no. of Childrens of "<<node->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i+1<<"th Child element of " <<node->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            node->children.push_back(child);
            q.push(child);

        }
    }
    return root;
}
int main(){
    
    TreeNode<int>* root = inputLevelWise();
    
    printTreeLevelWise(root);
    replaceWithDepthRec(root);
    // printRepalceTree(root,0);
    printRepalceTree(root);
    

}