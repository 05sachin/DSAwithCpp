// Given two generic trees, return true if they are structurally identical. Otherwise return false.
// Structural Identical
#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
bool identical(TreeNode<int>* root1,TreeNode<int>* root2){
    if(root1==NULL || root2==NULL ) return false;
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    
    if(root1->data!=root2->data){
        return false;
    }
    bool flag = true;
    for(int i=0;i<root1->children.size();i++){
        flag=flag && identical(root1->children[i],root2->children[i]);
        if(!flag) break;

    }
    return flag;
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
    TreeNode<int>* root1 = inputLevelWise();
    TreeNode<int>* root2 = inputLevelWise();
    cout<<"identical : "<<identical(root1,root2)<<endl;
    
    
    

}