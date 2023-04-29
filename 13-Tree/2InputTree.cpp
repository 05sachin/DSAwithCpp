#include<iostream>
#include<vector>
#include "TreeNode.h"
using namespace std;
void printTree(TreeNode<int>* root){
    if(root==NULL) return ;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
TreeNode<int>* inputTree(){
    int data;
    cout<<"Enter Data: "<<endl;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int n;
    cout<<"Enter no. of childrens of "<<data<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=inputTree();
        root->children.push_back(child);
    }
    return root;
}
int main(){
    /*TreeNode<int>* root=new TreeNode<int>(1);
    TreeNode<int>* node1=new TreeNode<int>(2);
    TreeNode<int>* node2=new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>* root = inputTree();
    printTree(root);

}
