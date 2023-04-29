// Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
int nextLargeRec(TreeNode<int>* root,int x){
    if(root==NULL) return -1;
    int ans=-1;
    if(root->data > x){
        ans=root->data;
    }
    for(int i=0;i<root->children.size();i++){
        int temp=nextLargeRec(root->children[i],x);
        if(temp!=-1){
            if(ans==-1){
                ans=temp;
            }else if(ans>temp){
                ans=temp;
            }
        }
    }
    return ans;

}
int nextLarge(TreeNode<int>* root,int x){
    if(root==NULL) return -1;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ans=-1;
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        if(node->data>x){
            if(ans==-1){
                ans=node->data;
            }else if(node->data<ans){
                ans=node->data;
            }
        }
        for(int i=0;i<node->children.size();i++){
            q.push(node->children[i]);
        }
    }
    return ans;
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
    int x;
    cin>>x;
    TreeNode<int>* root = inputLevelWise();
    
    // cout<<"next large : "<<nextLarge(root,x)<<endl;
    cout<<"next large : "<<nextLargeRec(root,x)<<endl;
    
    

}